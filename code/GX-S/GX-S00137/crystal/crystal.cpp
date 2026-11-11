#include<bits/stdc++.h>
using namespace std;
int a[100005];
struct Node
{
	int ch;
	int a,b;
}b[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,i,j,p=1,c=1,x=0,y=1,ma=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		cout<<c<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==0)
	{
		for(i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				c++;
			}
			else
			{
				c=1;
			}
			ma=max(ma,c);
		}
		cout<<ma<<endl;
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			b[p].ch=a[i]-a[j];
			b[p].a=j;
			b[p].b=i;
			p++;
		}
	}
	for(i=1;i<p;i++)
	{
		if(b[i].b!=b[i-1].b)
		{
			if(x<=m)
			{
				ma=max(ma,y);
			}
			x=0;
			y=1;
		}
		x+=b[i].ch;
		y++;
		if(i==p-1)
		{
			if(x<=m)
			{
				ma=max(ma,y);
			}
		}
	}
	cout<<ma<<endl;
	return 0;
}
