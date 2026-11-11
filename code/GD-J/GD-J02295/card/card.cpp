#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],b[n];
	long long c[1000005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt1=0,cnt2=0,cnt3=0;
	int i=n;
	for(int h=0;h<n*n;h++)
	{

		for(int i=0;i<n;i++)
		{
			s[i]=a[i];
			if(a[i]=1)
			{
				cnt1++;
				if(cnt1>1)
				{
					for(int j=i;j>b[0];j--)
					{
						s[j]=0;
					}
				}
				cnt1=0;
				b[0]=i;
			}
			if(a[i]=2)
			{
				cnt2++;
				if(cnt2>1)
				{
					for(int j=i;j>b[1];j--)
					{
						s[j]=0;
					}
				}
				cnt2=1;
				b[1]=i;
			}
			if(a[i]=3)
			{
				cnt3++;
				if(cnt3>1)
				{
					for(int j=i;j>b[2];j--)
					{
						s[j]=0;
					}
				}
				cnt3=1;
				b[2]=i;

			}
			i--;
		}
		c[i]=s.size();
		if(i=0)
		{
			break;
		}
	}
	int ans1=0,ans2=0,ans3=0;
	for(int i=0;i<n*n;i++)
	{
		if(c[i]=1)
		{
			ans1++;
		}
		if(c[i]=2)
		{
			ans2++;
		}
		if(c[i]=3)
		{
			ans3++;
		}
	}
	cout<<ans1<<ans2<<ans3;
	return 0;
 }
