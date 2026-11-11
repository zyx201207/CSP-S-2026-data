#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114514];
int ans = 0;
int vis[114514];
int b[114514];
bool flag=0;
void dfs(int dep,int g,int k)
{
	if(dep==g+1)
	{
//		cout<<a[k]<<endl;
		int tot = 0;
		for(int i=1;i<=g;i++)//²î 
		{
//			cout<<b[i]<<" ";
			tot += (a[k+1]) - b[i];
		}
//		cout<<tot<<endl;
		flag = (tot <=m ? 1 : 0);
		return ;
	}
	for(int i=1;i<=k;i++)//xxxx y
	{
		if(!vis[a[i]])
		{
			b[dep] = a[i];
			vis[a[i]]=1;
			dfs(dep+1,g,k);
			vis[a[i]]=0;
		}
	}
}
void solve(int x)
{
	flag = 0;
	int l=1,r=x-1;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		dfs(1,mid,x-1);
		if(flag)
		{
			l=mid;
			flag=0;
		}else{
			r=mid-1;
		}
	}
	ans = max(ans,r);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		solve(i);
	}
	cout<<ans+1;
}
//? is good i like it
