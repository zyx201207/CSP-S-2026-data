#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
int n,m;
vector<int>val[63];
void solve(int x)
{
	int cnt=0,pq=x;
	while(x)
	{
		if(x&1)
		{
			val[cnt].push_back(pq);
		}
		cnt++;
		x>>=1;
	}
	return;
}
const int MAXN=2e5+10;
int a[MAXN];
int tmp[MAXN],tot;
map<int,int>vis;
bool cmp(int a,int b)
{
	return a>b;
}
int fg;
int main()
{
	fre();
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i+1])
		{
			fg=1;
		}
	}
	if(fg==0)
	{
		cout<<a[1]<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		solve(a[i]);
	}
//	for(int i=0;i<62;i++)
//	{
//		sort(val[i].begin(),val[i].end(),greater<int>());
//	}
	for(int i=61;i>=0;i--)
	{
		for(int j=0;j<val[i].size();j++)
		{
			if(val[i].size()<2)continue;
			if(vis[val[i][j]]==0)
			{
				tmp[++tot]=val[i][j];
				vis[val[i][j]]=1;
			}
			if(tot>=m)break;
		}
		if(tot>=m)break;
	}
	ll ans=tmp[1];
	for(int i=1;i<=tot;i++)
	{
		ans&=tmp[i];
	}
	cout<<ans;
	return 0;
}

