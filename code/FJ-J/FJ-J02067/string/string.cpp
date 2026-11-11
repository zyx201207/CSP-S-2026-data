#include<bits/stdc++.h>
using namespace std;
int n,a[200005],z=0,ans;
char c[200005],cc[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=z+1;j<=z+a[i];j++)
		{
			cc[j]=c[i];
		}
		z+=a[i];
	}
	int x=z/2;
	for(int i=1;i<=x;i++)
	{
		if(cc[i]!=cc[z+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
