#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int> lis;
vector<int> ed;
vector<vector<int>> jyh;
vector<bool> vis;
vector<int> hs(int x){
	if(x==n)
		return {lis[x]};
	if(vis[x])
		return jyh[x];
	vis[x]=1;
	if(ed[lis[x]]!=x)
		return jyh[x]=hs(ed[lis[x]]);
	auto s=hs(x+1);
	s.push_back(lis[x]);
	return jyh[x]=s;
}
vector<int> ans;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	lis.resize(n+1);
	ed.resize(m+1);
	for(int i=1;i<=n;i++){
		cin>>lis[i];
		ed[lis[i]]=i;
	}
	jyh.resize(n+1);
	vis.resize(n+1);
	ans.resize(m);
	for(int i=1;i<=n;i++){
		auto ss=hs(i);
		for(auto it:ss)
			ans[it-1]++;
	}
	for(auto it:ans)
		cout<<it<<' ';
	return 0;
}

