#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
char s[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,ans=0,l,r;
	cin>>n;
	l=1;
	r=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		m+=a[i];
		cin>>s[i];
	}
	m/=2;
	while(m>0)
	{
		m-=a[l];
		if(m<0)
		{
			for(long long i=r;i>l;i--)
			{
				if(s[i]!=s[l])
				{
					ans+=a[i];
				}
			}
			cout<<ans;
			return 0;
		}
		else
		{
			while(a[l]>0)
			{
				a[l]-=a[r];
				if(a[l]<0)
				{
					a[r]-=(a[l]+a[r]);
					if(s[l]!=s[r])
					{
						ans+=(a[l]+a[r]);
					}
					l++;
					break;
				}
				else
				{
					if(s[l]!=s[r])
					{
						ans+=a[r];
					}
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
