#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],cnt,sum;
int ans,ma=-99999999;
int w1,w2,w3,w4;
bool A=true,B=true,C=true;
bool fun(int n)
{
	while(1)
	{
		if(n>1&&n%2!=0) return false;
		if(n==1) return true;
		n/=2;
	}
}
bool check(int n)
{
	while(1)
	{
		if(n>1&&n%2!=0) return false;
		if(n==1) return true;
		n/=2;
	}	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
		if(i-a[i]!=1) B=false;
		if(a[i]>4) C=false;
	}
	for(int i=1;i<=n;i++)
	{
		if(!fun(a[i]+1)) 
		{
			A=false;
		}
	}
	if(!check(n))
	{
		B=false;
	}
	sort(a+1,a+n+1);
	cnt=a[1];
	for(int i=2;i<=n;i++)
	{
		cnt&=a[i];
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	if(m==n)
	{
		cout<<cnt;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				sum=a[i];
				sum&=a[j];
				ans=max(ans,sum);
			}
		}
		cout<<ans;
		return 0;
	}
	if(A)
	{
		cout<<a[n-m+1];
		return 0;
	}
	if(B)
	{
		ans=a[n];
		for(int i=n-1;i>=(n-m+1);i--)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(C)
	{
		for(int i=n;i>=1;i--)
		{
			w1+=(a[i]==1);
			w2+=(a[i]==2);
			w3+=(a[i]==3);
			w4+=(a[i]==4);
		}
		if(w4>=m)
		{
			cout<<4;
			return 0;
		}
		else if(w3>=m)
		{
			cout<<3;
			return 0;
		}
		else if((w3+w2)>=m)
		{
			cout<<2;
			return 0;
		}
		else if((w3+w1)>=m)
		{
			cout<<1;
			return 0;
		}
		else 
		{
			cout<<0;
		}
	}
	return 0;
}
