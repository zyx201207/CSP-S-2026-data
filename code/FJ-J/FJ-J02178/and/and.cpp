#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200005],maxx=INT_MIN;
bool mp[200005];
void dfs(ll x,ll sum)				//25pts
{
	if(x==0)	maxx=max(maxx,sum);
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0)
		{
			mp[i]=1;
			dfs(x-1,sum&a[i]);
			mp[i]=0;
		}
	}
}
signed main()
{
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=20)	//È«ÅÅÁÐ
	{
		for(int i=1;i<=n;i++)
		{
			mp[i]=1;
			dfs(m-1,a[i]);
			mp[i]=0;
		}
		cout<<maxx;
		return 0;
	}
	if(m==1)					//5pts
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)					//5pts
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx&=a[i];
		}
		cout<<maxx;
		return 0;
	}
	if(n<=2000&&m==2)         			//15pts
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1)						//10pts
	{
		int pre[200005],pre_[200005];
		pre[1]=a[1];
		pre_[n]=a[n];
		for(int i=2;i<=n;i++)	pre[i]=pre[i-1]&a[i];
		for(int i=n-1;i>=1;i--)	pre_[i]=pre_[i+1]&a[i];
		for(int i=2;i<n;i++)	maxx=max(int(maxx),pre[i-1]&pre_[i+1]);
		cout<<max(pre_[2],max(pre[n-1],(int)maxx));
		return 0;
	}
	sort(a+1,a+n+1);
	maxx=a[n];
	for(int i=n-1;i>=m;i--)
	{
		maxx&=a[i];
	}
	cout<<maxx;
   	return 0;
}


