#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],ans;
vector<int>a1;
int n,m;
void dfs(int pos,int k)
{
	if(k==m)
	{
		int val=a1[0];
		for(int i=1;i<a1.size();i++)
			val=(val&a1[i]);
		ans=max(ans,val);
	}
	for(int i=pos;i<=n;i++)
	{
		a1.push_back(a[i]);
		dfs(i+1,k+1);
		a1.pop_back(); 
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int ans1=0;
		for(int i=1;i<=n;i++)
			ans1=max(ans1,a[i]);
		cout<<ans1;
		return 0;
	}
	if(m==n)
	{
		int ans1=a[1];
		for(int i=2;i<=n;i++)
			ans1=ans1&a[i];
		cout<<ans1;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
