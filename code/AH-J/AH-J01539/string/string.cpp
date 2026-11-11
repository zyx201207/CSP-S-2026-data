#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
vector<char> c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,to=0,t=0,ans=0;
	cin>>n;
	a.resize(n+1);
	c.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		to+=a[i];
	}
	if(to&1)
	{
		for(int i=1;i<=n;i++)
		{
			if(t+a[i]>=to/2+1&&t<to/2+1)
			{
				a[i]--;
				if(a[i]==0)
				{
					a.erase(a.begin()+i);
					c.erase(c.begin()+i);
					n--;
				}
				break;
			}
			t+=a[i];
		}
		to--;
	}
	t=0;
	for(int i=1;i<=n;i++)
	{
		if(t<to/2&&t+a[i]>to/2)
		{
			a.insert(a.begin()+i+1,t+a[i]-to/2);
			c.insert(c.begin()+i+1,c[i]);
			a[i]=to/2-t;
			n++;
			break;
		}
		t+=a[i];
	}
	int l=0,r=n+1,lm=0,rm=0;
	while(l<r-1)
	{
		int add;
		if(lm<=rm)
		{
			l++;
			if(lm+a[l]<=rm)
			{
				add=(c[l]==c[r])?0:a[l];
			}
			else
			{
				add=(c[l]==c[r])?0:rm-lm;
			}
			lm+=a[l];
		}
		else
		{
			r--;
			if(lm>rm+a[r])
			{
				add=(c[l]==c[r])?0:a[r];
			}
			else
			{
				add=(c[l]==c[r])?0:lm-rm;
			}
			rm+=a[r];
		}
		ans+=add;
	}
	cout<<ans;
	return 0;
}
