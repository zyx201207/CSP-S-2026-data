#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m;
bool cmp(int x,int y)
{
	return x>y;
}
bool p(int n)
{
	bool x=0;
	for(int i=1;i<=20;i++)
	{
		if((1<<i)==n)
		{
			x=1;
			break;
		}
	}
	if(x==1)return 1;
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
	{
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(p(n))
	{
		int t=a[1];
		m--;
		for(int i=2;i<=n;i++)
		{
			if(p(a[i]+1))
			{
				t=(t&a[i]);
				m--;
				if(m==0)break;
			}
		}
		cout<<t;
	}
	else
	{
		int t=a[1];
		for(int i=2;i<=m;i++)
		{
			t=(t&a[i]);
		}
		cout<<t;
	}
	return 0;
}
