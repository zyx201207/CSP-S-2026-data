//GZ-S00046 毕节东辰实验学校 漆高唤
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct SSS
{
	int zhi;
	int xb;
};

const int N=5e5+5;
int n;
ll m,a[N];
ll dp[5005][5005];
ll s,ans=0;
SSS d[N];
ll cnt[N];
int cha;

/*bool cmp(SSS x,SSS y)
{
	if(x.zhi!=y.zhi)
	{
		return x.zhi<y.zhi;
	}else return x.xb<y.xb;
}*/

bool cmp2(SSS x,SSS y)
{
	if(x.zhi!=y.zhi)
	{
		return x.zhi<y.zhi;
	}else return x.xb<y.xb;
}

void so()
{
	int anss;
	int k=0;
	//a[0]=-1;
	m=m/cha;
	m=m*2;
	while(m>=(k+1)*2)
	{
		k++;
		m-=2*k;
		anss++;
	}
	cout<<anss+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ok=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
		{
			ok=1;
		}
	}
	sort(a+1,a+1+n);
	cha=a[3]-a[2];
	if(ok==0)
	{
		cout<<n;
		return 0;	
	}
	for(int i=1;i<n;i++)
	{
		if(a[i+1]-a[i]!=cha)
		{
			ok=2;
			continue;
		}
	}
	if(ok!=2)
	{
		so();
		return 0;
	if(ok==2)
{	
	//	int res=6000;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dp[i][j]=(a[j]-a[i])*(j-1+i)+dp[i][j-1];
			}
		}
		ll book=-1;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(m-dp[i][j]>=0)
				{
					book=min(m-dp[i][j],book);
				}
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(m-dp[i][j]==book)
				{
					ans=j-i+1;
				}
			}
		}
			cout<<ans;
		return 0;
}
}
}
