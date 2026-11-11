#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int INF=1e9;
const int N=2e6+10;

int c,t;
int n;
ll d;
ll a[N],cha[N];
void solve()
{
	for(int i=1;i<=n;++i)
	{
		cha[i]=a[i]-a[i-1];
	}
	printf("0\n");
}
void solvea()
{
	if(n<=3)
	{
		printf("0\n");
		return;
	}
	ll cha=a[2]-a[1];
	ll kua=d/cha;
	ll len=2*kua-1;
	if(len<=1||n*1LL-len<=0)
	{
		printf("0\n");
		return;
	}
	printf("%lld\n",n*1LL-len);
}
void solveb()
{
	if(n<=3)
	{
		printf("0\n");
		return;
	} 
	int l=0,r=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]-a[1]>d)
		{
			r=i-1;
			break;
		}
	}
	if(r==0)
	{
		printf("0\n");
		return;
	}
	for(int i=n;i>=1;--i)
	{
		if(a[n]-a[i]>d)
		{
			l=i+1;
		}
	}
	if(l+1!=r)
	{
		printf("0\n");
		return;
	}
	ll left,right;
	for(int i=n;i>=1;--i)
	{
		if(a[r+1]-a[i]>d)
		{
			left=i;
			break;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]-a[l-1]>d)
		{
			right=i;
			break;
		}
	}
	printf("%lld\n",left*(n-right+1));
}
void input()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(11<=c&&c<=12)
	{
		while(t--)
		{
			input();
			solvea();
		}
	}
	else if(13<=c&&c<=14)
	{
		while(t--)
		{
			input();
			solveb();
		}
	}
	else
	{
		while(t--)
		{
			input();
			solvea();
		}
	}
}

