#include<bits/stdc++.h>
using namespace std;
int n,a[200009];
long long cnt=0;
char c[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	
	int o=n;
	
	for(int i=1;i<=o;i++)
	{
		if(c[i]!=c[o])
		{
			if(a[i]>a[o])
			{
				cnt+=abs(a[i]-a[o]);
				a[i]-=a[o];
				o--;
				i--;
			}
			else if(a[i]<a[o])
			{
				cnt+=abs(a[i]-a[o])*1ll;
				a[o]-=a[i];
				continue;
			}
			else if(a[i]==a[o])
			{
				cnt+=a[i];
				o--;
				continue;
			}
		}
		else
		{
			if(a[i]>a[o])
			{
				a[i]-=a[o];
				o--;
				i--;
			}
			else if(a[i]<a[o])
			{
				a[o]-=a[i];
				continue;
			}
			else if(a[i]==a[o])
			{
				o--;
				continue;
			}
		}
	}
	cout<<cnt;
	return 0; 
}
