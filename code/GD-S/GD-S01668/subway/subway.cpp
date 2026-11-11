#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=1e6+10;
int cc,n,m,d,q,len[N];
ll t[M],w[N][N],ans,cnt;
vector<pair<ll,ll> > a[M],b[M];
int main(){
//	system("fc subway.out subway6.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(w,0x3f,sizeof(w));
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&t[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++){
			int x;ll xx;
			scanf("%d %lld",&x,&xx);
			a[i].push_back({x,xx});
			b[x].push_back({i,xx});
		}
	}
//	cout<<111;
	for(int i=1;i<=m;i++){
		cnt+=b[i].size();
		for(auto tmp:b[i]){
			int u=tmp.first;
			ll val1=tmp.second;
			for(auto tmp2:b[i]){
				int v=tmp2.first;
				ll val2=tmp2.second;
				if(u==v) continue;
				w[u][v]=w[v][u]=min(w[u][v],val2+val1);
			}
		}
	}
//	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++) w[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				w[i][j]=min(w[i][k]+w[k][j],w[i][j]);
			}
		}
	}
	while(q--){
		int u,v;
		ans=w[0][0];
		scanf("%d %d",&u,&v);
		for(auto tmp:b[u]){
			for(auto tmp2:b[v]){
//				cnt++;
				ans=min(t[u]+t[v]+tmp.second+tmp2.second+w[tmp.first][tmp2.first],ans);
			}
		}
		printf("%lld\n",ans);
	}
//	cout<<cnt;
	return 0;
} 
