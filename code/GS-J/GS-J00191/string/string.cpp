#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%ld",&m);
		cin>>s[i-1];
		a[i]=m;
	}
	for(int i=1,j=n;i<j;i++,j--)
	{
		if(i=j-1)
		{
			if(s[i-1]==s[j-1])
			break;
			else
			c+=abs(a[i]-a[j]);
			
		}
		if(s[i-1]==s[j-1])
		{
			if(s[i]==s[i-1])
			{
				if(a[i]>a[j])
				a[i+1]+=a[i]-a[j];
				else
				a[j-1]+=a[j]-a[i];				
			}
			else
			c+=abs(a[i]-a[j]);
			continue;
		}
		else
		{
			if(a[i]>a[j])
			{
				c+=a[j];
				if(s[i]=s[i-1])
				{
					a[i+1]+=a[i]-a[j];
				}
				else
				{
					if(a[i+1]>a[j-1])
					{
						a[i+1]+=a[i]-a[j];
					}
					else
					{
						c+=a[i]-a[j];
						a[j-1]-=a[i]-a[j];
					}
				}
			}
			else
			{
				c+=a[i];
				if(s[j-2]=s[j-1])
				{
					a[j-1]+=a[j]-a[i];
				}
				else
				{
					if(a[j-1]>a[i+1])
					{
						a[j-1]+=a[j]-a[i];
					}
					else
					{
						c+=a[j]-a[i];
						a[i+1]-=a[j]-a[i];
					}
				}
			}
		}
	}
	cout<<c;
	return 0;
}
