#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,top=1;
long long a[1000005];
char c[1000005],op[1000005];
string s1,s2;
int flag=1;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<c[i]<<" ";
//	}
	for(int i=1;i<=n/2;i++)
	{

		if(c[i]==c[n+1-i])
		{	
			flag=1;	
			ans=0;
		}
		else 
		{
			flag=0;
			if(c[i]==c[n+1-i] and a[i]!=a[n+1-i])
			{
					
				ans+=abs(a[i]-a[n+1-i]);
			}
			else if(a[i]==a[n+1-i] and c[i]!=c[n+1-i])
			{
					
				ans+=a[i];
			}
			else flag=3;
		}
	}
	if(flag==3)
	{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			op[top]=c[i];
			top++;
		}
	}
	for(int i=1;i<=(top)/2;i++)
	{
		if(op[i]!=op[n+1-i])
		{	
			ans++;
		}
	}
	}
	if(flag==1)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
