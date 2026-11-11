#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[200020];
long long n,m;
vector<long long>q;
long long maxn=0;
long long mp[1000010];
void dfs(long long x,long long last)
{
	if(x>m)
	{
		long long ans=a[q[0]];
		for(long long i=0;i<q.size();i++)
		{
			ans&=a[q[i]];
		}
		maxn=max(maxn,ans);
		return ;
	}
	for(long long i=last+1;i<=n;i++)
	{
		q.push_back(i);
		dfs(x+1,i);
		q.pop_back();
	}
}
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long maxn1=0;
	long long ans1;
	bool A=1,B=1,C=1,D=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn1=max(maxn1,a[i]);
		if(i==1)ans1=a[i];
		else ans1&=a[i];
		if(!(a[i]==i-1))B=0;
		if(!(a[i]<=1024))D=0;
	}
	if(n<=20)
	{
		dfs(1,0);
		cout<<maxn;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn1;
		return 0;
	}
	if(m==n)
	{
		cout<<ans1;
		return 0;
	}
	if(n<=2000&&m==2)
	{
		long long maxn2=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				maxn2=max(maxn2,(a[i]&a[j]));
			}
		}
		cout<<maxn2;
		return 0;
	}
	if(m==n-1)
	{
		sort(a+1,a+n+1,cmp);
		long long ans11=a[1];
		for(long long i=1;i<=m;i++)
		{
			ans11&=a[i];
		}
		cout<<ans11;
		return 0;
	}
	if(B==1)
	{
		cout<<n-m;
		return 0;
	}
	if(D==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
//pts=25+25+10+35
