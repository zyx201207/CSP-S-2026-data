#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],num,b[200005][35]={0},c[35]={0};
void jisuan1(int jb,int k,long long ans)
{
	if(k==m)
	{
		num=max(num,ans);
		return;
	}
	if(jb>n)
	{
		return;
	}
	jisuan1(jb+1,k,ans);
	if(k==0)
	{
		jisuan1(jb+1,k+1,a[jb]);
	}
	else
	{
		ans=ans&a[jb];
		jisuan1(jb+1,k+1,ans&a[jb]);
	}
	return;
}
void jisuan2()
{
	for(int i=1;i<=n;i++)
	{
		long long x=a[i];
		int y=0;
		while(x>0)
		{
			if(x%2==1)
			{
				b[i][y]=1;
			}
			x=x/2;
			y++;
		}
	}
	for(int i=0;i<=35;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i]+=b[j][i];
		}
	}
	long long ans;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=0;j<=35;j++)
		{
			if(c[j]-b[i][j]>=m)
			{
				ans+=pow(2,i);
			}
		}
		num=max(num,ans);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2000)
	{
		jisuan1(1,0,0);
	}
	else if(m==n-1)
	{
		jisuan2();
	}
	else
	{
		jisuan1(1,0,0);
	}
	cout<<num;
	return 0;
}
