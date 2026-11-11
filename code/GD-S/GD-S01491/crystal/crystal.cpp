#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
long long n,m,a[N],ans=LONG_LONG_MIN,sum=1,l=1,x,ym;
signed main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ym=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	x=a[1];
	for(int i=2;i<=n;i++)
	{
		int c=a[i]-x,u=0;
		c=c*sum;
		if(m>=c)
		{
			m-=c;
			sum++;
			ans=max(ans,sum);
			x=a[i];
		}
		else
		{
			while(m<c&&l<i)
			{
				u=x-a[l];
				m+=u,l++,sum--;
				c=(a[i]-x)*sum;
			}
			if(m>=c)
			{
				m-=c;
				sum++;
				ans=max(ans,sum);
				x=a[i];
			}
			else
			{
				m=ym;
				l=i;
				sum=1;
				ans=max(ans,sum);
				x=a[i];
			}
		}
	}
	ans=max(ans,sum);
	cout<<ans;
	return 0;
}
