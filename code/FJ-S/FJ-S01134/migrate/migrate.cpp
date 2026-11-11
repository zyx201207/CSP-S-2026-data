#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N],ans[10005][10005],n,c,t,d,mi,sum;
void dfs(int now,int tar,int be,int cnt)
{
	if(now=tar)
	{
		if(now<mi)
		{
			ans[be][tar]=1;
			mi=now;
		}else
		{
			ans[be][tar]++;
		}
		return;
	}
	if(ans[be][tar]!=0)
	{
		if(cnt>=mi)
		{
			return;
		}
	}
	int go=now+d;
	for(int i=now;;i++)
	{
		if(x[i+1]<=go)
		{
			dfs(i+1,tar,be,cnt+1);
		}else
		{
			break;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dfs(i,j,i,0);
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(ans[i][j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
		/*
		if(x[n]-x[1]<=10*d)
		cout<<10<<'\n';
		else
		cout<<1<<'\n';
		*/
	}
	return 0;
}
