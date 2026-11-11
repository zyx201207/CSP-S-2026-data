#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,s[N],root,ans[M];
vector<int> e[M];
bool vis[M];
void dfs(int now,int fa){
	for(int i=0;i<(int)e[now].size();i++){
		int a=e[now][i]; 
		if(a==fa)continue;
		dfs(a,now);
		ans[now]+=ans[a];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=n;i>=1;i--){
		if(!vis[s[i]]){
			vis[s[i]]=1;
			if(i==n)root=s[i];
			else{
				e[s[i]].push_back(s[i+1]);
				e[s[i+1]].push_back(s[i]);
			} 
		}
		++ans[s[i]];
	}
	dfs(root,0);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
