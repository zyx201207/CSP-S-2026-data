#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cco;
int s[35];
pair<int,bool> a[200005];
int b[200005],top;

bool cmp(int x,int y)
{
	return x>y;
}

bool cp(pair<int,bool> x,pair<int,bool> y)
{
	return x.first>y.first;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].first);
		a[i].second=1;
	}
	int now=30,cnt=0;
	while(now>1)
	{
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));top=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].second==0) continue;
			for(int j=0;j<=30;j++)
			{
				if((1<<j)&a[i].first)
					s[j]++;
			}
		}
		for(int i=now-1;i>=0;i--)
		{
			if(s[i]>=m)
			{
				now=i;
				break;
			}
			if(i==0)
			now=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].second==0) continue;
			if((a[i].first&(1<<now))==0)
			{
				a[i].second=0;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			if(a[i].second==1)
				b[++top]=a[i].first;
		}
		sort(b+1,b+1+top,cmp);
		if(top>=m)
		{
			int ans=(1<<30)-1;
			for(int i=1;i<=m;i++)
				ans&=b[i];
			cco=max(cco,ans);
		}
	}
	cout << cco;
	return 0;
}
