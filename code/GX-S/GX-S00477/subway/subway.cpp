#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxq=1e5+10;
const int maxk=5e5+10;
const int maxm=5e5;
inline ll rd(){
	char c=getchar();ll k=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=k*10+c-'0';c=getchar();}
	return k*f;
}
int c,n,m,d,qnum;
ll ans[maxq];
struct node{int st,t;};
vector<node> a[510];
ll k[maxk];
ll f[510][510];
ll w[maxq];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}	
	}
}
void init(){
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=1e18;
	}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();qnum=rd();
	init();
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,st,t;j<=k[i];j++){
			cin>>st>>t;
			a[i].push_back((node){st,t}); //line i will go through st station
		}
		for(int j=0;j<k[i];j++){
			for(int z=0;z<k[i];z++){
				int x=a[i][j].st,y=a[i][z].st;
				if(x==y)continue;
				f[x][y]=a[i][x].t+a[i][y].t;
				f[y][x]=f[x][y];
			}
		}
	}
	floyd();
	for(int i=1;i<=qnum;i++){
		int x,y;
		cin>>x>>y;
		ans[i]=w[x]+w[y]+f[x][y]-1;
	}
	for(int i=1;i<=qnum;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
