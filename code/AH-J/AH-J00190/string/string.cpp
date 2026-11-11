#include<bits/stdc++.h>
using namespace std;
const long long N=200010;
long long n,m,sum,ans,l,r,a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	m=sum%2;
	sum/=2;
	for(long long i=1;i<=n;i++)
	{
		if(sum>=a[i])
		{
			sum-=a[i];
		}
		else
		{
			long long d=a[i]-sum-m;
			if(d>sum)
			{
				l=i-1;
				r=i;
				a[i]=d-sum;
			}
			else if(d<sum)
			{
				l=i;
				r=i+1;
				a[i]=sum-d;
			}
			else
			{
				l=i-1;
				r=i+1;
			}
			break;
		}
	}
	while(l>=1)
	{
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			ans+=a[r]*(c[l]!=c[r]);
			r++;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			ans+=a[l]*(c[l]!=c[r]);
			l--;
		}
		else
		{
			ans+=a[l]*(c[l]!=c[r]);
			l--;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
