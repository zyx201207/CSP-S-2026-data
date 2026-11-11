#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,m,ans,maxn;
int a[N],num[11];
bool st[N];
void dfs(int dep,int sum)
{
	if(dep>m)
	{
		if(sum>ans)ans=sum;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			st[i]=1;
			dfs(dep+1,(sum&a[i]));
			st[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
	int k=(1<<20)-1;
	if(n<=20)
	{
		dfs(1,k);
		cout<<ans<<endl;
	}
	else if(n<=2000)
	{
		if(m==1)ans=maxn;
		else if(m==2)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)ans=max(ans,(a[i]&a[j]));
		}
		else
		{
			ans=k;
			for(int i=1;i<=n;i++)
				ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	else if(maxn==4)
	{
		for(int i=1;i<=n;i++)
			num[a[i]]++;
		if(num[4]>=m)cout<<4<<endl;
		else if(num[3]>=m)cout<<3<<endl;
		else if(num[3]+num[2]>=m)cout<<2<<endl;
		else if(num[3]+num[1]>=m)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
