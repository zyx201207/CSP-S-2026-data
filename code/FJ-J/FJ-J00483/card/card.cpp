#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
vector<int>vec[300001];
bool vis[300001];
int ans[300001];
void dfs(int x){
	if(x>n)return;
	int l=(int)vec[a[x]].size();
	int now=vec[a[x]][l-1];
	for(int i=x;i<now;i++){
		vis[i]=true;
	}
	dfs(now+1); 
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vec[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		dfs(i);
		for(int j=i;j<=n;j++){
			if(!vis[j])ans[a[j]]++;
		}
		memset(vis,false,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
