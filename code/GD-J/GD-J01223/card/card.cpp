# include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,cnt[1000005];
vector<int>son[1000005];
void dfs(int x){for(int i:son[x])dfs(i),cnt[x]+=cnt[i];}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--){
		if(cnt[a[i]]==0&&i<n)son[a[i+1]].push_back(a[i]);
		cnt[a[i]]++;
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
