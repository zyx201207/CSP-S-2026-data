#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define N 500005
/*int head[N],nxt[N],ver[N],tot,edg[N];
void add(int x,int y,int z){
	ver[++tot]=y;edg[tot]=z;
	nxt[tot]=head[x];head[x]=tot;
}*/
vector<pair<int,int> > tg[N];int a[N];
ll f[502][502];//floyd
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int id,n,m,d,q;cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;tg[a].push_back({i,t});
			//cerr<<"EDGE: "<<a<<" -> "<<i<<","<<t<<endl;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)	f[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=tg[i].size();
		for(int j=0;j+1<sz;j++){
			int e1=tg[i][j].second,p1=tg[i][j].first;
			for(int k=j+1;k<sz;k++){
				int e2=tg[i][k].second,p2=tg[i][k].first;
				f[p1][p2]=f[p2][p1]=min(f[p1][p2],(ll)(e1+e2));
				//cerr<<"EDGE: "<<p1<<" "<<p2<<" : "<<e1<<"+"<<e2<<endl;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;ll ans=f[0][0];//=inf 
		for(int i=0;i<tg[x].size();i++){
			int p1=tg[x][i].first,e1=tg[x][i].second;
			for(int j=0;j<tg[y].size();j++){
				int p2=tg[y][j].first,e2=tg[y][j].second;
				//cerr<<"NOW: "<<p1<<" "<<p2<<" : "<<e1+e2<<" "<<f[p1][p2]<<endl;
				ans=min(ans,f[p1][p2]+e1+e2);
			}
		}
		cout<<(ans+a[x]+a[y])<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
