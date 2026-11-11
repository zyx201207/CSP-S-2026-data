#include<iostream>
#include<vector>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q;
int w[M];
int k[N],a[N][M],t[N][M];
int x[Q],y[Q];
vector<int>lin[M];
vector<int>sta[N];
bool vis[M];
int dfs(int pos,int des,int tim){
	if(pos==des)return tim;
	int mn=114514;
	for(auto l:lin[pos]){
		for(auto v:sta[l]){
			if(!vis[v]){
				vis[v]=1;
				mn=min(mn,dfs(v,des,t[l][pos]+t[l][v]));
				vis[v]=0;
			}
		}
	}
	return tim+mn;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			lin[a[i][j]].push_back(i);
			sta[i].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=w[x[i]]+w[y[i]];
		ans+=dfs(x[i],y[i],0);
		cout<<ans<<'\n';
	}
	return 0;
}
