#include<bits/stdc++.h>
using namespace std;
long long a[10005],cnt;
int i;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char s[10005];
	cin>>n;
	for(int j=0;j<n;j++)
	{
		cin>>a[j]>>s[j];
	}
	while(i<n-1)
	{
		if(s[i]==s[n-1])
		{
			if(a[i]>a[n-1])
			{
				if(s[i]!=s[n-2])
				{
					cnt+=(a[i]-a[n-1]);
					n--;
				}
				else
				{
					a[n-2]+=(a[n-1]-a[i]);
					if(a[n-2]<=0)
					{
						a[n-3]+=a[n-2];
						n-=2;
					}
				}
			}
			else
			{
				if(s[i]!=s[n-2])
				{
					cnt+=(a[n-1]-a[i]);
					n--;
				}
				else
				{
					a[i+1]+=(a[i]-a[n-1]);
					if(a[i+1]<=0)
					{
						a[i+2]+=a[i+1];
						i++;
					}
				}
			}
			i++;
		}
		else
		{
			if(a[i]>a[n-1])
			{
					cnt+=a[n-1];
					n--;
			}
			else
			{
				if(a[i]<a[n-1])
			    {
					cnt+=a[i];
					i++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
