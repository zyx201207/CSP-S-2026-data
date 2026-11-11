#include<iostream>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		len=len+a[i];
	}
	long long x=1,y=n,ans=0;
	while(x<y)
	{
		if(b[x]!=b[y])
		{
			if(a[x]==a[y])
			{
				ans=ans+a[x];
				x++;
				y--;
			}
			else if(a[x]<a[y])
			{
				ans=ans+a[x];
				a[y]=a[y]-a[x];
				x++;
			}
			else
			{
				ans=ans+a[y];
				a[x]=a[x]-a[y];
				y--;
			}
		}
		else
		{
			if(a[x]==a[y])
			{
				x++;
				y--;
			}
			else if(a[x]<a[y])
			{
				a[y]=a[y]-a[x];
				x++;
			}
			else
			{
				a[x]=a[x]-a[y];
				y--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
