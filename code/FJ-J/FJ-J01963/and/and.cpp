#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
clock_t st;

void dfs(int i,int x,int ch)
{
	if(ch==m)
	{
		ans=max(ans,x);
		return;
	}
	if(i==n)return;
	if((n-i)+ch<m)return;
	if(x<=ans&&ch!=0)return;
	if(x==0&&ch==0)
	{
		dfs(i+1,a[i],ch+1);
	}
	else dfs(i+1,x&a[i],ch+1);
	dfs(i+1,x,ch); 
}
void solve1()
{
	dfs(1,0,0);
	cout<<ans<<endl;
}
//int maxt=1000000,t=0;
void dfs2(int i,int x,int ch)
{
//	t++;
	if(ch==m)
	{
		ans=max(ans,x);
		return;
	}
//	if(t>=maxt)
//	{
//		cout<<ans<<'\n';
//		exit(0);
//	}
	if(i==n)return;
	if((n-i)+ch<m)return;
	if(x<=ans&&ch!=0)return;
	if(x==0&&ch==0)
	{
		dfs(i+1,a[i],ch+1);
	}
	else dfs(i+1,x&a[i],ch+1);
	dfs(i+1,x,ch); 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	st=clock();
	sort(a+1,a+n+1,greater<int>());
	if(m==n)
	{
		int an=a[1];
		for(int i=2;i<=n;i++)an&=a[i];
		cout<<an<<endl;
		return 0;
	}
	if(m==1)
	{
		cout<<a[n]<<endl;
		return 0;
	}
	if(n<=20)
	{
		solve1();
		return 0;
	}
//	cout<<"Gg\n";
	dfs2(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
/*
T3 and 50+eps/100 pts
10:45~11:30
超级大暴力。
找不到任何性质。
绿~青。
这还是-J吗。 
*/
