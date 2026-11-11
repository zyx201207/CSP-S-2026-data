#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=30;k>=0;k--)
	{
		int x=1<<k;
		vector<int> v;
		v.push_back(0);
		int t=0;
		for(int i=1;i<=n;i++)
		{
			t+=(a[i]&x)!=0;
		}
		if(t<m) continue;
		ans+=x;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&x) v.push_back(a[i]);
		}
		a=v;
		n=a.size()-1;
	}
	cout<<ans;
	return 0;
}
