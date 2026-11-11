#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>

int rd(){
	int k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){k*=10;k+=(c-'0');c=getchar();}
	return k*f;
}

const int N=507,M=5e5+7,D=27,Q=1e5+7;

int c,b,n,m,d,q;

int w[M],k[N];
vector<int>a[N],t[N];
long long dist[N][N];

vector<PII>zt[M];

void solve(){
	int x=rd(),y=rd();
	if(x==y){
		cout<<0<<'\n';
		return ;
	}
	long long ans=LLONG_MAX;
	for(PII it_u:zt[x]){
		for(PII it_v:zt[y]){
			int line1=it_u.first,line2=it_v.first,
			val1=it_u.second,val2=it_v.second;
			ans=min(ans,dist[line1][line2]+val1+val2);
		}
	}
	cout<<ans+w[x]+w[y]<<'\n';
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++){
		k[i]=rd();
		for(int j=1;j<=k[i];j++){
			int op1=rd(),op2=rd();
			a[i].push_back(op1);
			t[i].push_back(op2);
			zt[op1].push_back({i,op2});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=m;i++){
		for(PII it_u:zt[i]){
			for(PII it_v:zt[i]){
				int u=it_u.first,v=it_v.first,
				val_u=it_u.second,val_v=it_v.second;
				if(u==v)continue;
				dist[u][v]=val_u+val_v;
			}
		} 
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); 
			}
		}
	}
	while(q--)solve();
//	cout<<dist[1][3];
	return 0;
}
