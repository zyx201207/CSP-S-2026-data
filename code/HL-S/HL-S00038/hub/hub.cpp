#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,K;
vector<int> To[N];
int dis[N];
void dfs(int x){
	for(int y:To[x]){
		if(dis[x]+1<dis[y]){
			dis[y]=dis[x]+1;
			dfs(y);
		}
	}
}
void Main(){
	cin>>n>>K;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		To[x].push_back(y);
		To[y].push_back(x);
	}
	int ans=N+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=n;k++){
				dis[k]=N+1;
			}
			dis[i]=0;dfs(i);dis[j]=0;dfs(j);
			int res=0;
			for(int k=1;k<=n;k++){
				res=max(dis[k],res);
			}
			ans=min(res,ans);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TC,T;cin>>TC>>T;
	while(T--) Main();
	return 0;
}