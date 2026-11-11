#include<bits/stdc++.h>
using namespace std;
long long m,n,a[5000005];
bool def[5000005];
long long t[5000005];
long long find(int x,long long t[5000005])//x keshu t nengliangshi
{
	long long m=0,sum=0;
	for(int i=1;i<=x;i++)
	{
		m=max(m,t[i]);
	}
	for(int i=1;i<=x;i++)
	{
		sum+=m-t[i];
	}
	return sum;
}
void dfs(long long g,long long x)
{
	if(g>x)
	{
		int q=1;
		for(int i=1;i<=n;i++)
		{
			if(def[i])
			{
				t[q]=a[i];
				q++;
			}
		}
			if(find(x,t)<=m)
			{
				cout<<x;
				exit(0);
			}
			else
			{
				return;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(!def[i])
		{
			def[i]=1;
			dfs(g+1,x);
			def[i]=0;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(i==1)
		{
			cout<<"1";
			return 0;
		}
		dfs(1,i);
	}
	return 0;
}
