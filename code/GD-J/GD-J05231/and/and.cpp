#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool flaga=true,flagb=true,flagc=true;
bool isall1(int x)
{
	for(int i=0;i<30;i++)
	{
		if(x==(1<<i)-1)return true;
	}
	return false;
}
bool is2pow(int x)
{
	for(int i=0;i<30;i++)
	{
		if(x==(1<<i))return true;
	}
	return false;
}
int ANS=-1;
void dfs(int dep,int sum,int chose)
{
	if(dep>n)
	{
		if(chose==m)ANS=max(ANS,sum);
		return ;
	}
	dfs(dep+1,sum,chose);
	if(chose<m)dfs(dep+1,sum&a[dep],chose+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(!is2pow(n))flagb=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!isall1(a[i]))flaga=false;
		if(a[i]!=i-1)flagb=false;
		if(a[i]>=4)flagc=false;
	}
	if(n<=20)//1-5
	{
		dfs(1,(1<<30)-1,0);
		cout<<ANS;
	}
	else if(m==1)//6
	{
		int ans=-1;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2)//7
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(m==n)//8-10
	{
		int ans=(1<<30)-1;
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1)//11 12
	{
		int ans=-1;
		a[0]=a[n+1]=(1<<30)-1;
		for(int i=1;i<=n;i++)a[i]=a[i]&a[i-1];
		for(int i=1;i<=n;i++)ans=max(ans,a[i-1]&a[i+1]);
		cout<<ans;
	}
	else if(flaga or flagb)//13 1415
	{
		sort(a+1,a+1+n);
		int ans=(1<<30)-1;
		for(int i=n;i>=n-m+1;i--)ans=ans&a[i];
		cout<<ans;
	}
	else if(flagc)//16 17
	{
		int num[4]={0};
		for(int i=1;i<=n;i++)num[a[i]]++;
		if(num[3]>=m)cout<<3;
		else if(num[3]+num[2]>=m)cout<<2;
		else if(num[3]+num[1]>=m)cout<<1;
		else cout<<0;
	}
	return 0;
}
