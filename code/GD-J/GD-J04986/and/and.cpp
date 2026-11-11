#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool cmp(int x,int y){return x<y;}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int maxn=-1;
	int sumn;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sumn=maxn;
	for(int i=1;i<=n;i++)
	{
		sumn=(sumn&a[i]);
	}
	if(n<=20)
	{
		int ma=-1;
		for(int S=0;S<(1<<(n+1))-1;S++)
		{
			int cnt=0,sum=maxn;
			for(int i=1;i<=n;i++)
			{
				if((1<<i)&S)
				{
					cnt++;
					sum=(sum&a[i]);
				}
				if(cnt>m) break;
			}
			if(cnt!=m) continue;
			ma=max(ma,sum);
		}
		cout<<ma;
	}
	else if(m==1)
	{
		cout<<maxn;
	}
	else if(m==n)
	{
		cout<<sumn;
	}
	else if(m==2)
	{
		int ma=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
	}
	else if(m==n-1)
	{
		int ma=-1;
		int sum=maxn;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				sum=(sum&a[j]);
			}
			ma=max(ma,sum);
		}
		cout<<ma;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		int sum=maxn;
		for(int i=1;i<=m;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	return 0;
}
