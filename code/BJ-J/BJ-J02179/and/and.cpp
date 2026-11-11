#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[200010];
int t1[200010],t2[200010],l1,l2;
int a[200010];
string change(int a)
{
	string t="";
	while(a)
	{
		t+=(a%2==1?'1':'0');
		a/=2;
	}
	return t;
}
int f(int z)
{
	int res=1;
	while(z--)res*=2;
	return res;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mh=0,flag1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=1;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2)
	{
		int p=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				p=max(p,a[i]&a[j]);
			}
		}
		cout<<p;
	}
	else
	{
		for(int i=1;i<=n;i++)
			s[i]+=change(a[i]);
		for(int i=30;i>=0;i--)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(s[j][i]=='1')cnt++;
			}
			if(cnt>=m)
			{
				for(int j=1;j<=n;j++)
				{
					if(s[j][i]=='1')t1[++l1]=j;
				}
				mh=i;
				flag1=1;
				break;
			}
		}
		if(flag1==1)
		{
			int ans=0;
			for(int j=mh;j>=0;j--)
			{
				int cnt=0;
				for(int i=1;i<=l1;i++)
				{
					if(s[t1[i]][j]=='1')cnt++;
				}
				if(cnt==m)ans+=f(j);
			}
			cout<<ans;
		}
		else cout<<0;
	}
	return 0;
}
