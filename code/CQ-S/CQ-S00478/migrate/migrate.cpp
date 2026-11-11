#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
int x[N],vis[N],dis[N],b[5010][5010],minn[N];
int cmp(int x,int y){
	return x>y;
}
struct node{
	int to,w;
};
vector<node> e[N];
void dfs(int x,int s,int fa){
	minn[x]=min(minn[x],s);
	b[x][minn[x]]++;
	for(auto v: e[x]){
		if(v.to==fa){
			continue;
		}
		dfs(v.to,s+1,x);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int d,len;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(b,0,sizeof(b));
		memset(minn,1e9,sizeof(minn));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					e[i].push_back({j,1});
				}
			}
		}
		int ans=0;
		//cout<<b[dis[n]]<<"\n";
		memset(minn,1e9,sizeof(minn));
		for(int i=1;i<=n;i++){
			dfs(i,0,0);
			for(int j=i+1;j<=n;j++){
				//cout<<b[j][minn[j]]<<" "<<i<<" "<<j<<" "<<minn[j]<<'\n';
				if(b[j][minn[j]]==2){
					ans++;
					//cout<<i<<" "<<j<<"\n";
				}
			}
			memset(minn,1e9,sizeof(minn));
			memset(b,0,sizeof(b));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//最短路径走的步数一定一样，只是顺序不同 
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/

