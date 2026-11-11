#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[2000005],s;
void f(long long l,long long g,long long h)
{
	if(g==m)
	{
		s=max(s,h);
		return; 
	}
	for(int i = l;i<=n;i++)
	{
		f(i,g++,h&i);
	} 
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	} 
	stable_sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
	}
	else
	if(m==2)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(i!=j)
				{
					s=max(s,(a[i]&a[j]));
				} 
			}
		}
		cout<<s;
	}
	else
	if(m==3)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				for(int k = j;k<=n;k++)
				{
					s=max(s,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<s;
	}
	else
	if(n==m)
	{
		for(int i = 1;i<=n;i++)
		{
			s&=a[i];
		}
		cout<<s;
	} 
	else
	if(n==m-1)
	{
		for(int i = 2;i<=n;i++)
		{
			s&=a[i];
		}
		cout<<s;
	}
	else
	{
		f(1,1,0);
		cout<<s;
	}
	return 0;
}
//Àî¼Î¾þ GD-J03853 
