#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],la[300005];
vector<int>s[500005];
int si[500005];
void dfs(int w){
	si[w]=1;
	for(int i=s[w].size()-1;i>-1;--i)
		dfs(s[w][i]),si[w]+=si[s[w][i]];
	ans[a[w]]+=si[w];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i],la[a[i]]=i;
	for(int i=n;i>0;--i)
		s[la[a[i]]+1].emplace_back(i);
	dfs(n+1);
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<" ";
	return 0;
}
