#include<bits/stdc++.h>
using namespace std;
int a[200005],ans=0,n,m;
void dfs(int i,int sum,int ch,int xing)
{
//	cout<<i<<' '<<sum<<' '<<ch<<' '<<xing<<endl;
	if(i>n+1)
		return; 
	if(ch==m)
	{
		ans=max(sum,ans);
		return;
	}
	if(sum==0)
	{
		dfs(i+1,0,ch,xing*10+0);
		dfs(i+1,a[i],ch+1,xing*10+1); 
	}	
	else
	{
		dfs(i+1,sum,ch,xing*10);
		dfs(i+1,sum&a[i],ch+1,xing*10+1);
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool A=1,B=1;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
	}
	else if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else if(m==n-1)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt=max(cnt,ans&a[i]);
		cout<<cnt;
	}
	else if(maxx<=4)
	{
		int num[5];
		for(int i=1;i<=n;i++)
		{
			num[a[i]]++;
		}
		if(num[4]>=m)
			cout<<4;
		else if(num[3]>=m)
			cout<<3;
		else if(num[2]+num[3]>=m)
			cout<<2;
		else if(num[3]+num[1]>=m)
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0; 
} 
