#include<bits/stdc++.h>
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define int long long
using namespace std;
using pii=pair<int,int>;
int n,m;
int a[500010];
int mx=-TNF;
bool st[500010];
void dfs(int x,int cnt,int r)
{
	if(r==m)
	{
		mx=max(mx,cnt);
		return ;
	}
	if(cnt==x)
	{
		mx=max(mx,cnt);
		return ;
	}
	for(int i=1;i<=x;i++)
	{
		if(st[i]==1)continue;
		st[i]=1;
		if(m>=r+a[x]-a[i])dfs(x,cnt+1,r+a[x]-a[i]);
		st[i]=0;
	}
}
int ss[500010];
int sss[500100];
void d()
{
	cin>>n>>m;
	int r=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)r=1;
	}	
	if(r==0)
	{
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			ss[i]=ss[i-1]+(i-1);
			if(m>=ss[i])cnt++;
			else break;
		}
		cout<<cnt<<endl;
		return ;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		sss[i]=a[i]-a[i-1];
		if(i==2)continue;
		if(sss[i]!=sss[i-1])r=0;
	}
	if(r==1)
	{
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			ss[i]=ss[i-1]+sss[i]*(i-1);
			if(m>=ss[i])cnt++;
			else break;
		}
		cout<<cnt<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)	dfs(i,1,0);
	cout<<mx<<endl;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)d();
}


