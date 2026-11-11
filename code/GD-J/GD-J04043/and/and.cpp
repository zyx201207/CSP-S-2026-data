#include<bits/stdc++.h>
using namespace std;
//#define ll long long
const int N=2e5+5;
int n,m;
int a[N];
int p1=0,p2=0;
int tr1[N<<1][2];
int cnt1[N<<1][2];
int tr2[N<<1][2];
int cnt2[N<<1][2];
vector<int> num[N<<4][2];
int ans1=0;
int ans2=0;
void Insert(int x)
{
	int root=0;
	for(int i=20;i>=0;i--)
	{
		int now=((x>>i)&1);
		if(!tr1[root][now])
			tr1[root][now]=++p1;
		cnt1[root][now]++;
		root=tr1[root][now];
	}
	root=0;
	for(int i=0;i<=20;i++)
	{
		int now=((x>>i)&1);
		if(!tr2[root][now])
			tr2[root][now]=++p2;
		cnt2[root][now]++;
//		cout<<(int)num[root][now].size()<<"\n";
		num[root][now].push_back(x);
		root=tr2[root][now];
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	int root=0;    
	for(int i=20;i>=0;i--)
	{
		if(tr1[root][1])
		{
			if(cnt1[root][1]>=m)
			{
//				cout<<cnt[root][1]<<" "<<i<<"\n";
				ans1+=(1<<i);
				root=tr1[root][1];
				continue;
			}
		}
		root=tr1[root][0];
	}
	root=0;
	for(int i=0;i<=20;i++)
	{
		if(tr2[root][1])
		{
			if(cnt2[root][1]>=m)
			{
				sort(num[root][1].begin(),num[root][1].end(),cmp);
				int ttn=num[root][1][0];
				for(int ppp=1;ppp<(int)num[root][1].size() and ppp<m;ppp++)
					ttn&=num[root][1][ppp];
				ans2=max(ans2,ttn);
				root=tr2[root][1];
				continue;
			}
		}
		root=tr2[root][0];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Insert(a[i]);
	}
	solve();
	cout<<max(ans1,ans2);
	return 0;
}
