#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
LL a[200010];
LL ans=0;
bool f[200010];
void dfs(int k,LL sum,int rp)
{
	if(rp==m)
	{
		ans=max(ans,sum);
		
		return ;
	}
	if(k>n)
	{
		return ;
	}
	for(int i=k;i<=n;i++)
	{
		if(!f[i])
		{
			if(k==1||rp==0)
			{
				f[i]=1;
				dfs(k+1,a[i],rp+1);
				f[i]=0;
			}
			else
			{
				f[i]=1;
				dfs(k+1,(sum&a[i]),rp+1);
				f[i]=0;
			}
		}
	}
	dfs(k+1,sum,rp);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	LL summ,maxx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)summ=a[i];
		else summ=(summ&a[i]);
		maxx=max(a[i],maxx);
	}
	if(m==n)
	{
		cout<<summ;
		return 0;
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
