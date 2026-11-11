#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m,a[N],vis[N],cnt[N],xb,ans[N];
bool pd=0;
void solve1()
{
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i+1])
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cnt[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<cnt[i]<<" ";
		}
		exit(0);
	}
	int sum=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			sum++;
		}
		else
		{
			sum++;
			cnt[a[i]]=sum;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i+1])
		{
			pd=1;
		}
		else
		{
			pd=0;
			break;
		}
	}
	if(pd)
	{
		solve1();
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]!=0)
			{
				for(int k=vis[a[j]];k<=j-1;k++)
				{
					ans[k]=1;
				}
				vis[a[j]]=0;
			}
			vis[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			if(ans[j]==0)
			{
//				cout<<a[j]<<" ";
				cnt[a[j]]++;
			}
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
