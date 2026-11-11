#include<bits/stdc++.h>
using namespace std;
#define int long long // <------------------------
int TTTQQQTTT,T;
int n,d;
int a[2000001];
int ans;
int cnt=0;
void dfs(int x,int r,int cs,int y)
{
	//cout<<x<<" "<<r<<" "<<cs<<" "<<y<<endl;
	if(cs<=0) return;
	if(cnt>2) return;
	/*if(x==r)
	{
		if(y>d) return;
		if(cs==1)
		{
			cnt++;
		}
		return;
	}
	int dis=a[x+1]-a[x];
	if(y<=d) dfs(x+1,r,cs-1,dis);
	if(dis+y>d) return;
	dfs(x+1,r,cs,dis+y);*/
	if(x==r)
	{
		if(y+a[r]-a[r-1]>d) return;
		if(cs==1) cnt++;
		return;
	}
	int dis=a[x+1]-a[x];
	if(y+dis>d) return;
	dfs(x+1,r,cs-1,0);
	dfs(x+1,r,cs,y+dis);
}
int hs(int l,int r)
{
	int minn=1;
	int k=a[l+1]-a[l];
	if(k>d) return 0;
	for(int i=l+1;i<=r;i++)
	{
		if(k>d)
		{
			minn++; k=a[i]-a[i-1];
			continue;
		}
		k+=a[i]-a[i-1];
	}
	cnt=0;
	dfs(l+1,r,minn,0);
		//cout<<"qqqq "<<l<<" "<<r<<" "<<cnt<<" "<<minn<<endl;
	if(cnt==2)
	{
		return 1;
	}
	return 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>TTTQQQTTT>>T;
	if(TTTQQQTTT==11||TTTQQQTTT==12)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n==1)
			{
				cout<<"0"<<'\n'; continue;
			}
			int q=a[2]-a[1];
			if(d<q) 
			{
				cout<<"0"<<'\n'; continue;
			}
			int f=d/q;
			if(f<2)
			{
				cout<<"0"<<'\n'; continue;
			}
			int w=f*2;
			cout<<max(0ll,n-w+1)<<'\n';
			/*int q=a[2]-a[1];
			if(q*2<=d&&d<=3*q)
			{
				cout<<n-4+1<<'\n';
			}
			else cout<<"0"<<'\n';*/
		}
		return 0;
	}
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1)
		{
			cout<<"0"<<'\n'; continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=hs(i,j);
			}
		}
		cout<<ans<<'\n';
		//hs(1,6);
	}
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 6
1 3 5 7 9 11 13 15 17

11 1
10 22
0 7 14 21 28 35 42 49 56 63



*/
