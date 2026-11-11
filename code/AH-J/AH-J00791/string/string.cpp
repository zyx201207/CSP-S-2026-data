#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s,t=0,n,k1=0,k2=0,c1=0,c2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		t+=a[i];
	}
	s=t/2;
	for(int i=1;i<=n;i++)
	{
		c1++;
		k1+=a[i];
		if(k1>=s)
		{
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		c2++;
		k2+=a[i];
		if(k2>=s)
		{
			break;
		}
	}
	int l=1,r=n;
	while(l<=c1&&r>=n-c2+1)
	{
		if(b[l]==b[r])
		{
			if(a[l]<a[r])
			{
				s-=a[l];
				a[r]-=a[l];
				a[l]-=a[l];
			}
			else
			{
				s-=a[r];
				a[l]-=a[r];
				a[r]-=a[r];
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				a[l]-=a[l];
			}
			else
			{
				a[l]-=a[r];
				a[r]-=a[r];
			}
		}
		if(a[l]<=0)
		{
			l++;
		}
		if(a[r]<=0)
		{
			r--;
		}
	}
	cout<<s;
	return 0;
}
