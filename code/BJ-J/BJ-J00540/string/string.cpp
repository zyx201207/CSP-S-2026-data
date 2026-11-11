//T2
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200001],now,sum,pos,ans;
char c[200001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;++i)
	{
		now+=a[i];
		if(now>=(sum+1)/2)
		{
			pos=i;
			break;
		}
	}
	if(sum%2==1)
	{
		a[pos]--;
		sum--;
	}
	now=0;
	for(int i=1;i<=n;++i)
	{
		now+=a[i];
		if(now>=sum/2)
		{
			pos=i;
			break;
		}
	}
	for(int i=pos,j=pos;i<=n;++i)
	{
		if(i==j)
		{
			int r=now-sum/2,l=sum/2-now+a[pos];
			if(l>r)
			{
				a[pos]-=r*2;
				i++;
			}
			else if(r>l)
			{
				a[pos]-=l*2;
				j--;
			}
			else
			{
				a[pos]=0;
				i++;
				j--; 
			}
		}
		while(a[i]>=a[j]&&j>=1)
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		if(a[i]&&a[j]>=a[i])
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
		}
	}
	cout<<ans;
	return 0;
}
