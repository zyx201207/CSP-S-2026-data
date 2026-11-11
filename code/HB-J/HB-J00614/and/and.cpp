#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
bool vis[200005];
bool cmp(int a,int b){ return a>b; }
void dfs(int s,int f,long long num)
{
	if(f>m)
	{
		ans=max(ans,num);
		return;
	}
	vis[s]=true;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i,f+1,num&a[i]);
	}
	vis[s]=false;
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++) cin>>a[i],ans=max(ans,a[i]);
	}
	else if(n==m)
	{
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++) cin>>a[i],ans=ans&a[i];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++) ans=max(ans,a[j]&a[i]);
		}
	}
	else
	{
		int flag,aflag=1;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			flag=0;
			for(int j=1;j<=32;j++)
			{
				if(a[i]==pow(2,j)-1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0) aflag=0;
		}
		sort(a+1,a+n+1,cmp);
		if(aflag==1) ans=a[m];
		else 
		{
			for(int i=1;i<=n;i++) dfs(i,1,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
