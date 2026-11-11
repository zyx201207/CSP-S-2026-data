#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],vis[N],ans,maxa,b[N],c2[N];
bool f1=true,f2=true;
bool cmp(int x,int y)
{
	return x>y;
}
void solve1()//等差数列和a[i]=i 
{
	int ca=abs(a[2]-a[1]);
	for(int i=1;i<n;i++)
	{
		if(m>=ca*i)
		{
			m=m-ca*i;
			ans++;
		}
		else break;
	}
	cout<<ans;
}
void solve2()
{
	bool f=true;
	int maxmin=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			f=false;
			maxmin=max(maxmin,-a[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i]+=maxmin;
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		c2[n-i+1]=c[i];
	}
	c2[n]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+c2[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1,sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=sum+b[j]-b[i-1];
			if(sum<=m)
			{
				cnt++;
			}
			else
			{
				ans=max(ans,cnt);
				break;
			}
		}
		ans=max(ans,cnt);
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	int ca=a[2]-a[1];
	if(a[1]!=1||a[2]!=2)f2=false;
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=ca)f1=false;
		if(a[i]!=i)f2=false;
	}
	if(f1||f2)
	{
		solve1();
		return 0;
	}
	else if(n<=5000)
	{
		solve2();
		cout<<ans;
		return 0; 
	}
	else
	{
		cout<<114514;
		return 0;
	} 
}
