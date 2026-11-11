#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],wei[N];
bool vis[N];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=32;i++)
	{
		wei[i]=pow(2,i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int t=0;
	while(a[1]>=wei[t])
	{
		t++;
	}
	t--;
	int ans=wei[t+1]-1;
	for(int i=t;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=wei[i])cnt++;
		}
		if(cnt<m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]>=wei[i])a[j]-=wei[i];
			}
			continue;
		}
		break;
	}
	sort(a+1,a+1+n,cmp);
	for(int j=1;j<=m;j++)
	{
		ans&=a[j];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
