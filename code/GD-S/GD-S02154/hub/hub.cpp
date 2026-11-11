#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+5;
int c,T,n,k,x,y,ans,f[N];
vector<int> t[N];
bool yf[N],vis[N];
void cdfs(int x,int fa){
	vis[x]=1;
	for(int i=0;i<t[x].size();i++){
		int y=t[x][i];
		if(y!=fa&&yf[y])cdfs(y,x);
	}
}
bool check(){
	for(int i=1;i<=n;i++)vis[i]=0;
	int s=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&yf[i]){
			s++;
			cdfs(i,0);
		}
	return (s<=2&&s>=1);
}
void dfs(int x,int fa,int s){
	f[x]=min(f[x],s);
	for(int i=0;i<t[x].size();i++){
		int y=t[x][i];
		if(y!=fa)dfs(y,x,s+1);
	}
}
int calc(){
	int s=0;
	for(int i=1;i<=n;i++)f[i]=n+1;
	for(int i=1;i<=n;i++)if(yf[i])dfs(i,0,0);
	for(int i=1;i<=n;i++)s=max(s,f[i]);
	return s;
}
void DFS(int x,int K){
	if(K==k){
		if(check())ans=min(ans,calc());
		return ;
	}
	if(x>n)return ;
	DFS(x+1,K);
	yf[x]=1;
	DFS(x+1,K+1);
	yf[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ans=n+1;
		for(int i=1;i<=n;i++)t[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			t[x].push_back(y);
			t[y].push_back(x);
		}
		DFS(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
