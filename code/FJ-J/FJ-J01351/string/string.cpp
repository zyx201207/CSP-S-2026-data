#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
	int a;
	char c;
}e[200002];
int n,m;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].c;
		len+=e[i].a;
	}
	int ans=0;
	int l=1;
	int r=n;
	while(l<=r)
	{
		if(l==r)
		{
			break;
		}
		int less=min(e[l].a,e[r].a);
		if(e[l].c!=e[r].c)
		{
			ans+=min(e[l].a,e[r].a);
			if(less==e[l].a)
			{
				e[r].a-=less;
				l++;
			}
			else
			if(less==e[r].a)
			{
				e[l].a-=less;
				r--;
			}
		}
		else
		{
			if(less==e[l].a)
			{
				e[r].a-=less;
				l++;
			}
			else
			if(less==e[r].a)
			{
				e[l].a-=less;
				r--;
			}
		}
	}
	cout<<ans;
}
