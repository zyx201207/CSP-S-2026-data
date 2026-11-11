#include<bits/stdc++.h>
using namespace std;

int n,sum=0,cnt=0,ans=0,a[200005],ans1=0;
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(c[i]==c[i-1]) 
		{
			a[i-1]+=a[i];
			a[i]=0;
			i--;
			n--;
		}
	} 
	sum/=2;
	for(int i=1;i<=n;i++)
	{
		int cur=0;
		while(a[n-i+1-cur]<=a[i]&&c[i]!=c[n-i+1-cur])
		{
			if(a[n-i+1]<=sum)
			{
				ans+=a[n-i+1];
				c[n-i+1]=c[i];
				sum-=a[n-i+1];
			}
			else
			{
				ans+=sum;
				break;
			}
			cur++;
		}
	}
	for(int i=n;i>=1;i--)
	{
		int cur=0;
		while(a[n-i+1-cur]<=a[i]&&c[i]!=c[n-i+1-cur])
		{
			if(a[n-i+1]<=sum)
			{
				ans1+=a[n-i+1];
				c[n-i+1]=c[i];
				sum-=a[n-i+1];
			}
			else
			{
				ans1+=sum;
				break;
			}
			cur++;
		}
	}
	cout<<min(ans,ans1);
	return 0;
} 
