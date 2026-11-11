#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,x,y;
int c[N];
char d[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		c[i]=a;
		d[i]=b;
	}
	for(int i=1,j=n;i<j;)
	{
		if(d[i]==d[j])
		{
			if(c[i]>c[j])
			{
				c[i]-=c[j];
				j--;
			}
			else if(c[i]<c[j])
			{
				c[j]-=c[i];
				i++;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(c[i]>c[j])
			{
				ans+=c[j];
				c[i]-=c[j];
				j--;
			}
			else if(c[i]<c[j])
			{
				ans+=c[i];
				c[j]-=c[i];
				i++;
			}
			else
			{
				ans+=c[i];
				i++;
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
