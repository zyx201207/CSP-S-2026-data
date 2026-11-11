#include<bits/stdc++.h>
using namespace std;
long long a[200100];
long long n,ans=0;
char b[200100];
int hi(int x,int y)
{
	if(x>=y)
	{
		cout<<ans; 
		return 0;
	}
	if(b[x]==b[y])
	{
		if(a[x]>a[y])
		{
			a[x]=a[x]-a[y];
			y--;
			hi(x,y);
		}
		else if(a[x]<a[y])
		{
			a[y]=a[y]-a[x];
			x++;
			hi(x,y);
		}
		else
		{
			x++;
			y--;
			hi(x,y);
		}
	}
	else
	{
		if(a[x]>a[y])
		{
			ans=ans+a[y];
			a[x]=a[x]-a[y];
			y--;
			hi(x,y);
		}
		else if(a[x]<a[y])
		{
			ans=ans+a[x];
			a[y]=a[y]-a[x];
			x++;
			hi(x,y);
		}
		else
		{
			ans=ans+a[x];
			x++;
			y--;
			hi(x,y);
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	hi(1,n);
	return 0;
}

