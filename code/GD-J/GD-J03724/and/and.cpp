#include <bits/stdc++.h>
using namespace std;
const int N=200015;
int n,m;
int a[N];
int vis[N];
int ans;
void solve1(int num,int cnt)
{
//	cout<<cnt<<endl;
	if(cnt>=m)
	{
//		cout<<num<<endl;
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(cnt==0)
			{
//				cout<<a[i]<<endl;
				solve1(a[i],cnt+1);
			}
			else
			{
				int tmp=num&a[i];
//				cout<<tmp<<endl;
				solve1(tmp,cnt+1);
			}
			vis[i]=0;
		}
	}
}
int maxx=0;
int sum=0;
void solve2()
{
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx<<endl;
		return;
	}
	else if(m==2)
	{
		int tmp=0;
		for(int i=1;i<=n;i++)
		{
			tmp=a[i];
			for(int j=i+1;j<=n;j++)
			{
				tmp=(tmp&a[j]);
				maxx=max(maxx,tmp);
			}
		}
		cout<<maxx<<endl;
		return;
	}
	else // m==n
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2000 && (m==1 || m==n || m==2))
	{
		solve2();
	}
	else if(n<=20)
	{
		solve1(0,0);
		cout<<ans;
	}
	return 0;
}
