#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

int n,m,ans;
vector<int> a,nxt;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	For(i,n)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=30;i>=0;i--)
	{
		nxt={};
		for(int it:a) if(it&(1ll<<i))
			nxt.push_back(it);
		if(nxt.size()>=m)
		{
			ans=ans|(1ll<<i);
			a=nxt;
		}
	}
	cout<<ans;
	return 0;
}
