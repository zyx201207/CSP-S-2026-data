#include <iostream>
#include <cmath>
using namespace std;
long long a[200005],ans,b[200005];
int n,m;
void dfs(int d)
{
	if(d==n+1)
	{
		long long num=0,x=pow(2,31)-1;
		for(int i=1;i<=n;i++)
		{
			num+=b[i];
			if(b[i]==1)
			{
				x=x&a[i];
			}
		}
		if(num==m)
		{
			ans=max(ans,x);
		}
		return;
	}
	b[d]=0;
	dfs(d+1);
	b[d]=1;
	dfs(d+1);
	b[d]=0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool pd=1,pd2=1;
	long long num=1;
	while(num<n)
	{
		num*=2;
	}
	if(num!=n)
	{
		pd=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>=4)
		{
			pd2=0;
		}
		if(a[i]!=i-1)
		{
			pd=0;
		}
	}
	if(n<=20)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(pd)
	{
		int x=0;
		num=1;
		while(num<n)
		{
			x++;
			num*=2;
		}
		int x2=x-m;
		if(x2<0)
		{
			cout << 0;
			return 0;
		}
		x2++;
		cout << pow(2,x2)-1;
		return 0;
	}
	if(pd2)
	{
		int sum0=0,sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				sum0++;
			}
			if(a[i]==1)
			{
				sum1++;
			}
			if(a[i]==2)
			{
				sum2++;
			}
			if(a[i]==3)
			{
				sum3++;
			}
		}
		int sum4=sum3;
		if(sum4>=m)
		{
			cout << 3;
			return 0;
		}
		sum4+=sum2;
		if(sum4>=m)
		{
			cout << 2;
			return 0;
		}
		sum4-=sum2;
		sum4+=sum1;
		if(sum4>=m)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
	}
}












































































































//感谢来自CCF的恩赐（划掉）部分分，至少100+100+70+0=270































//——————————————————————————————————————————————————————这是理论最高分————————————————————————————————————————————

































































































