#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct num
{
	int s,e;
}a[2005];
int n,m,maxn=INT_MIN,b[200005];
bool cmp(num a,num b)
{
	if(a.e==b.e) return a.s>b.s;
	else return a.e>b.e;
}
bool comp(int a,int b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m) 
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(ans==-1) ans=x;
			else ans&=x;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		sort(b+1,b+1+n,comp);
		int ans=b[1];
		for(int i=2;i<n;i++)
		{
			ans&=b[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		sort(b+1,b+1+n,comp);
		cout<<b[1]<<endl;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		int maxn=INT_MIN;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(b[i]&b[j]));
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;	
		int tmp=a[i].s,ans=0;
		while(tmp)
		{
			if(tmp%2==1) ans++;
			tmp/=2;
		}
		a[i].e=ans;
	}
	sort(a+1,a+1+n,cmp);	
	int cnt=a[1].s;
	for(int i=2;i<=m;i++)
	{
		cnt&=a[i].s;
	}
	cout<<cnt<<endl;
	return 0;
}

