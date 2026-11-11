#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10; 

int n,m;
int a[N];
int cnt[5050][5050];
int ans=0;
bool flag;

bool cmp(int a,int b)
{
	return a<b;
}

bool en;
int cha=0;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==2)
		{
			cha=a[2]-a[1];
		}
		else if(i>=2)
		{
			if(cha!=a[i]-a[i-1])
			{
				en=true;
			}
		}
		if(a[i]!=i)
		{
			flag=true;
		}
	}
	sort(a+1,a+n+1,cmp);
	
//	for(int i=1;i<=n;i++)
//	{
//		cnt[i]=0;
//	}
	if(!flag)
	{
		int num=0;
		int tot=1;
		for(int i=1;i<=n;i++)
		{
			if(num+i<=m)
			{
				num+=i;
				tot++;
			}
		}
		printf("%lld\n",tot);
		return 0;
	}
	
	if(!en)
	{
		//printf("!\n");
		int uum=0;
		int oto=1;
		for(int i=1;i<=n;i++)
		{
			if(uum+i*cha<=m)
			{
				uum+=i*cha;
				oto++;
			}
		}
		printf("%lld\n",oto);
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cnt[i][j+1]=cnt[i][j]+j*(a[i+j]-a[i+j-1]);
//			if(cnt[j+1]<=m)
//			{
//				ans=max(ans,j);
//			}
			//printf("%lld\n",cnt[i][j]);
		}
	}
//	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(cnt[i]<=m)
//		{
//			ans=max(ans,i);
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(cnt[i][j]<=m)
			{
				ans=max(ans,j);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
