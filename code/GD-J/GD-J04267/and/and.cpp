#include<bits/stdc++.h>
using namespace std;

int a[200005];

int ans=0;
int n;

map<pair<int,int>,int> mp;

int dfs(int i,int d)
{	
	if(mp.count({i,d})) return mp[{i,d}];
	
	if(d==0)
	{
		return -1;
	}
	int m=-1;
	for(int j=i+1;j<n;j++)
	{	
		m=max(dfs(j,d-1),m);
	}
	m&=a[i];
	mp[{i,d}]=m;
	return m;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	
	int ans=0;
	
	for(int i=0;i<=n-m;i++) ans=max(ans,dfs(i,m));
	cout<<ans;
	
	return 0;
}
