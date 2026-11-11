#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=INT_MIN,flg=1,flg2=1;
long long a[200005];
long long inf=2e30-1;
long long chu(long long n)
{
	long long ans=0;
	while(n%2==0) 
	{
		n/=2;
		ans++;
	}
	if(n!=1) return -1;
	else return ans;
}
bool cmp(long long x,long long y)
{
	return x>y;
}
void dfs(long long step,long long sum,long long pos)
{
	if(step==m+1) 
	{
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=pos;i<=n;i++)
	{
		dfs(step+1,(sum&a[i]),i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(chu(a[i]+1)==-1) flg=0;
		if(a[i]>3) flg2=0;
	} 
	if(n<=20)
	{
		dfs(1,inf,1);
		cout<<maxn;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++) inf&=a[i];
		cout<<inf;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++) inf&=a[i];
		for(int i=1;i<=n;i++) maxn=max(maxn,(inf|a[i]));
		cout<<maxn;
	}
	else if(chu(n)!=-1)
	{
		long long ans=0,s=0,t=chu(n);
		if(m*2>n) cout<<0;
		else
		{
			while(n)
			{
				ans++;
				n/=2;
				if(m>n) break;
			}
			for(int i=1;i<ans;i++) s+=pow(2,t-i);
			cout<<s;
		}
	}
	else if(flg==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else if(flg2==1)
	{
		long long s=0,s2=0,s3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) s++;
			if(a[i]==2) s2++;
			if(a[i]==3) s3++;
		}
		if(s3>=m) cout<<3;
		else
		{
			if((s2+s3)>=m) cout<<2;
			else if((s+s3)>=m) cout<<1;
			else cout<<0;
		}
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++) inf&=a[i];
		cout<<inf;
	}
	return 0;
}
