#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5,INF=1e18;
int n,m,q;
int simc[M];
struct T{ll v,w;};
vector<T>sta[M];
ll len[N][N];
int read(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')s=s*10-'0'+c,c=getchar();
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int gm;
	gm=read(),n=read(),m=read(),gm=read(),q=read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			len[i][j]=len[j][i]=INF;
	
	for(int i=1;i<=m;i++)simc[i]=read();
	for(int i=1;i<=n;i++){
		int sum=read();
		for(int j=1;j<=sum;j++){
			int l=read(),t=read();
			sta[l].push_back({i,t});
		}
	}
	
	for(int i=1;i<=m;i++)
		for(T x:sta[i])
			for(T y:sta[i]){
				if(x.v==y.v)continue;
				len[x.v][y.v]=len[y.v][x.v]=min(len[y.v][x.v],x.w+y.w);
			}
	for(int y=1;y<=n;y++)
		for(int x=1;x<=n;x++)
			for(int z=x+1;z<=n;z++){
				len[x][z]=min(len[x][z],len[x][y]+len[y][z]);
				len[z][x]=len[x][z];
			}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans;ans=INF;
		for(T u:sta[x]){
			for(T v:sta[y]){
				ans=min(ans,len[u.v][v.v]+u.w+v.w);
			}
		}
		cout<<simc[x]+simc[y]+ans<<"\n";
	}
	return 0;
}
