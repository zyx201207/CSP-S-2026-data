#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],x,ans;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c;
		s+=c;
	}
	bool f=0;
	int i=0,j=n-1;
	while(i<=j)
	{
		if(x==0)
		{
			c=s[i];
			x=a[i];
			f=0;
			continue;
		}
		if(f==0)
		{
			if(c==s[j])
			{
				if(x==a[j])
				{
					i++;
					j--;
					x=0;
				}
				else if(x<a[j])
				{
					x=a[j]-x;
					i++;
					f=1;
				}
				else
				{
					x-=a[j];
					j--;
				}
			}
			else
			{
				if(x==a[j])
				{
					ans+=x;
					i++;
					j--;
					x=0;
				}
				else if(x<a[j])
				{
					ans+=x;
					c=s[j];
					x=a[j]-x;
					i++;
					f=1;
				}
				else
				{
					ans+=a[j];
					x-=a[j];
					j--;
				}
			}
		}
		else
		{
			if(c==s[i])
			{
				if(x==a[i])
				{
					i++;
					j--;
					x=0;
				}
				else if(x<a[i])
				{
					x=a[i]-x;
					j--;
					f=0;
				}
				else
				{
					x-=a[i];
					i++;
				}
			}
			else
			{
				if(x==a[i])
				{
					ans+=x;
					i++;
					j--;
					x=0;
				}
				else if(x<a[i])
				{
					ans+=x;
					c=s[i];
					x=a[i]-x;
					j--;
					f=0;
				}
				else
				{
					ans+=a[i];
					x-=a[i];
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
