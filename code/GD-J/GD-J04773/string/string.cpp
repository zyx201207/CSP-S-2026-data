#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans=0,l=1;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(c[i]!=c[n-i+1])
		{
			if(a[i]>a[n-i+1])
			{
				ans+=a[i];
				int t=a[i]-a[n-i+1];
				for(int j=1;;j++)
				{
					if(a[n-i+1-j]-t<0)
					{
						t-=a[n-i+1-j];
						a[n-i+1-j]=0;
					}
					else 
					{
						a[n-i+1-j]-=t;
						break;
					}
				}
			}
			else 
			{
				ans+=a[n-i+1];
				int t=a[n-i+1]-a[i];
				for(int j=1;;j++)
				{
					if(a[i+1+j]-t<0)
					{
						t-=a[i+1+j];
						a[i+1+j]=0;
					}
					else
					{
						a[i+1+j]-=t;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
