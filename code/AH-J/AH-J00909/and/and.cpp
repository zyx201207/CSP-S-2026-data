#include<bits/stdc++.h>
using namespace std;
int a[200005];
int sum[200005];
int f[200005];
int maxnn,n,m;
void dfs(int k,int t)
{
	if(k==m+1)
	{
		maxnn=max(maxnn,t);
		return;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(f[i]==0 && (t&a[i])>maxnn)
		{
			f[i]=1;
			dfs(k+1,(t&a[i]));
			f[i]=0;
		}
	}
}
int qufan (int x)
{
	int i;
	string s;
	int t=0;
	while(x)
	{
		s+=x%2+'0';
		x/=2;
	}
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			s[i]='1';
		else
			s[i]='0';
	}
	for(i=0;i<s.size();i++)
	{
		t+=(s[i]-'0')*pow(2,i);
	}
	return t;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,maxn;
	cin>>n>>m;
	sum[0]=0x3f;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]&sum[i-1];
	}
	if(m==1)
	{
		maxn=0;
		for(i=1;i<=n;i++)
			maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==n)
	{
		cout<<sum[n];
	}
	else if(m==2)
	{
		maxn=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				maxn=max(maxn,(a[i]&a[j]));
		cout<<maxn;
	}
	else if(m==n-1)
	{
		maxn=0;
		for(i=1;i<=n;i++)
			maxn=max(maxn,qufan(sum[n]^a[i]));
		cout<<maxn;
	}
	else
	{
		dfs(1,0x3f);
		cout<<maxnn;
	}
}
