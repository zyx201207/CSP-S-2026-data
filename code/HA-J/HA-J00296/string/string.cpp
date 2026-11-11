#include<bits/stdc++.h>
using namespace std;
int a[200002];
char b[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int x=1,y=n;
	long long sum=0;
	while(x<y)
	{
		if(b[x]==b[y])
		{
			if(a[x]<a[y])
			{
				a[y]-=a[x];
				x++;
			}
			else if(a[x]>a[y])
			{
				a[x]-=a[y];
				y--;
			}
			else if(a[x]==a[y])
			{
				x++,y--;
			}
		}
		else
		{
			if(a[x]<a[y])
			{
				a[y]-=a[x];
				sum+=1ll*a[x];
				x++;
			}
			else if(a[x]>a[y])
			{
				a[x]-=a[y];
				sum+=1ll*a[y];
				y--;
			}
			else if(a[x]==a[y])
			{
				sum+=1ll*a[x];
				x++,y--;
			}
		}
	}
	cout<<sum;
}
