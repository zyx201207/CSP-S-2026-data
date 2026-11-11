#include<bits/stdc++.h>
using namespace std;
//string s,s1;
int n;
int a[200005];
long long r[200005];
char c[200005];
long long ans=0;
void f(int x,int y)
{
	if(r[x]>r[n]/2||r[y]<r[n]/2)
	{
		return;
	}
	if(c[x]!=c[y])
	{
		if(a[x]>=a[y])
		{
			ans+=a[y];
		}
		else
		{
			ans+=a[x];
		}
	}
	if(a[x]>=a[y])
	{
		a[x]-=a[y];
		f(x,y-1);
	}
	else
	{
		a[y]-=a[x];
		f(x+1,y);
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
//	long long a,r=0;
//	char c;
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
//		for(int j=r+1;j<=r+a;j++)
//		{
//			s[j]=c;
//		}
		r[i]=r[i-1]+a[i];
	}
//	int s=r/2;
//	for(int i=1;i<=n/2;i++)
//	{
//		if(c[i]!=c[n-i+1])
//		{
//			if(a[i]>=a[n-i+1])
//			{
//				ans+=a[n-i+1];
//			}
//			else
//			{
//				ans+=a[i];
//			}
//		}
//		if(a[i]>=a[n-i+1])
//		{
//			a[i]-=a[n-i+1];
//			if(c[i]!=c[n-i])
//			{
//				if(a[i]>=a[n-i])
//				{
//					ans+=a[n-i];
//				}
//				else
//				{
//					ans+=a[i];
//				}
//			}
//			if(a[i]>=a[n-i])
//			{
//				a[i]-=a[n-i];
//			}
//			else
//			{
//				a[n-i]-=a[i];
//			}
//		}
//		else
//		{
//			a[n-i+1]-=a[i];
//			if(c[n-i+1]!=c[i+1])
//			{
//				if(a[n-i+1]>=a[i+1])
//				{
//					ans+=a[i+1];
//				}
//				else
//				{
//					ans+=a[n-i+1];
//				}
//			}
//			if(a[n-i+1]>=a[i+1])
//			{
//				a[n-i+1]-=a[i+1];
//			}
//			else
//			{
//				a[i+1]-=a[n-i+1];
//			}
//		}
//	}
//	for(long long i=1;i<=r/2;i++)
//	{
//		s1[i]=s[r+1-i];
//		if(s1[i]!=s[i])
//		{
//			ans++;
//		}
//	}

	f(1,n);
	cout<<ans<<endl;
	return 0;
}
