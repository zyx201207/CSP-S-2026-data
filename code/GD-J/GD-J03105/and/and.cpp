#include<bits/stdc++.h>
using namespace std;
struct node
{
	int now;
	int two;
}a[200003];
bool cmp(node a,node b)
{
	if(a.two>b.two)
	{
		return a.two>b.two;
	}
	else if(a.now>b.now)
	{
		return a.now>b.now;
	}
}
int n,m,t,k,all,t_,num_;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==n)
	{
		scanf("%d",&all);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&k);
			all=all&k;
		}
		printf("%d",all);
		return 0;
	}
	else if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(k>all)
			{
				all=k;
			}
		}
		printf("%d",all);
		return 0;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			a[i].now=k;
			t=0;
			while(k==0)
			{
				t+=k%2;
				k/=2;
			}
			a[i].two=t;
		}
		sort(a,a+n,cmp);
		all=a[0].now;
		for(int i=1;i<m;i++)
		{
			all=all&a[i].now;
		}
		printf("%d",all);
		return 0;
	}
}
