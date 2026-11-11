#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int mx=0;
int mn=2147483647;
bool A=1,B=1;
void dfs(int ad,int s,int p)
{
	if(p>n)
	{
		if(s==m)
		{
			mx=max(mx,ad);
		}
		return;
	}
	if(s!=m)
	{
		dfs(ad&a[p],s+1,p+1);
	}
	dfs(ad,s,p+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(A==1)if(a[i]!=1&&a[i]!=3&&a[i]!=7&&a[i]!=15&&a[i]!=31&&a[i]!=63&&a[i]!=127&&a[i]!=255&&a[i]!=511&&a[i]!=1023&&a[i]!=2047&&a[i]!=4095&&a[i]!=8191&&a[i]!=16383&&a[i]!=32767&&a[i]!=65535&&a[i]!=131071&&a[i]!=262143&&a[i]!=524281&&a[i]!=1048575&&a[i]!=2097151)A=0;
		if(B==1)if(a[i]!=i-1)B=0;
		mn=min(mn,a[i]);
	}
	if(n<=20)
	{
		dfs(2147483647,0,1);
		cout<<mx;
	}
	else if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n)
	{
		int ans=2147483647;
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n-1)
	{
		int ans=2147483647;
		int min=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]<min)
			{
				ans=ans&min;
				min=a[i];
			}
			else 
			{
				ans=ans&a[i];
			}
		}
		cout<<ans;
	}
	else if(A)
	{
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m];
	}
	else if(B)
	{
		int t=1;
		while(t<m)
		{
			t=t*2;
		}
		cout<<n-t;
	}
	else if(mn<=4)
	{
		int book[9];
		for(int i=1;i<=n;i++)
		{
			book[a[i]]++;
		}
		if(mn==1)
		{
			if(book[1]>=m)cout<<1;
			else cout<<0;
		}
		else if(mn==2)
		{
			if(book[2]>=m)cout<<2;
			else if(book[1]>=m)cout<<1;
			else cout<<0;
		}
		else if(mn==3)
		{
			if(book[3]>=m)cout<<3;
			else if(book[2]>=m)cout<<2;
			else if(book[3]+book[2]>=m)cout<<2;
			else if(book[1]>=m)cout<<1;
			else cout<<0;
		}
		else if(mn==4)
		{
			if(book[4]>=m)cout<<4;
			else if(book[3]>=m)cout<<3;
			else if(book[2]>=m)cout<<2;
			else if(book[3]+book[2]>=m)cout<<2;
			else if(book[1]>=m)cout<<1;
			else cout<<0;
		}
	}	
	return 0;
}
