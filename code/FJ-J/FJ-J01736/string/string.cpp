#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,s[30],minn;
struct check{
	int num;
	char b;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char t='0',step=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		if(t!=y)
		{
			step++;
			a[step].num=x;
			a[step].b=y;
		}
		else
		{
			a[step].num+=x;
		}
	}
	int f=1;
	for(int i=1;i<=step/2+1;i++)
	{
		int j=step+1-i;
		if(a[i].num!=a[j].num||a[i].b!=a[j].b)
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=step/2+1;i++)
	{
		int j=n+1-i;
		if(a[i].b!=a[j].b)
		{
			ans+=a[j].num;
		}
	}
	cout<<ans;
	return 0;
 }
