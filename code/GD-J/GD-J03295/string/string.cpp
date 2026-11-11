#include<bits/stdc++.h>
using namespace std;
char a[10000],b[10000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t,longx=0,ans=0;
	char x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t>>x;
		for(int j=longx;j<longx+t;j++)
			a[j]=x; 
			longx+=t;
	}
	int o=0;
	for(int i=longx-1;i>=0;i--)
	{
		
		b[i]=a[o];
		o+=1;
	}
	for(int i=0;i<=(longx-1)/2;i++)
	{
		if(a[i]!=b[i])
		{
			a[i]=b[i];
			ans++;
		}
		
	}
	cout<<ans;
	return 0;
 } 
