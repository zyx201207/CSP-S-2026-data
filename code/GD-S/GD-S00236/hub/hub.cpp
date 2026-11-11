#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n,k,u,v;
vector<int> g[N];
int l,r,mid,ans;
void solve()
{
	cin>>n>>k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	l = 1;
	r = n;
	ans = n;
	
	return;
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

