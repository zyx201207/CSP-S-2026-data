#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h=INT_MIN,a[200005];
bool flag[200005];
void dfs(int h1,int step)
{
	if(step==m)
	{
		h=max(h,h1);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==true)
		{
			continue;
		}
		flag[i]=true;
		dfs(h1&a[i],step+1);
		flag[i]=false;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			flag[i]=true;
			dfs(a[i],1);
		}
	}
	else if(n<=2000&&n>20)
	{
		if(m==1)
		{
			h=a[n]; 
		}
		else if(m==n)
		{
			h=a[1];
			for(int i=1;i<=n;i++)
			{
				h&=a[i];
			}
		}
		else if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j)
					{
						continue;
					}
					h=max(h,a[i]&a[j]);
				}
			}
		}
	}
	else if(n>2000&&n<=200000)
	{
		for(int i=1;i<=n;i++)
		{
			flag[i]=true;
			dfs(a[i],1);
		}
	} 
	cout<<h<<endl;
	return 0;
}
