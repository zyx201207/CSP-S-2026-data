#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,ans;//Two pointers
struct node
{
	int x;
	char c;
};
node a[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	r=n-1;
	for(int i=0;i<n;i++)
	{
		if(l>=r)break;
		if(a[l].x>a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
		}
		else if(a[l].x<a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		}
		else if(a[l].x==a[r].x)
		{
			if(a[l].c!=a[r].c)
			{
				ans+=a[l].x;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

