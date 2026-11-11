#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i>=(r);i--)
#define first fir
#define second sec
const int MAXN=1e5+5,INF=0x7fffffff;
int n,m,ans,t[10];
vector<int> a,vis;
void dfs(int x,int num,int sum)
{
	if(num==m)
	{
		ans=max(ans,sum);
		return;
	}
	For(y,1,n)
		if(!vis[y]) vis[y]=1,dfs(y,num+1,sum&a[y]),vis[y]=0;
}
void sol1()
{
	sort(a.begin()+1,a.end(),greater<int>());
	For(i,1,m) ans&=a[i];
	cout<<ans;
}
void sol2()
{
		
}
void sol3()
{
	vis.resize(n+1);
	dfs(0,0,INF);
	cout<<ans;
}
void sol4()
{
	if(t[4]>=m) cout<<4;
	else if(t[3]>=m) cout<<3;
	else if(t[2]+t[3]>=m) cout<<2;
	else if(t[1]+t[3]>=m) cout<<1;
	else cout<<0;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,a.resize(n+1);
	bool ok=1;
	For(i,1,n)
	{
		cin>>a[i];
		if(a[i]<=4) t[a[i]]++;
		else ok=0;
	}
	if(m==n) sol1();
	else if(m==n-1) sol1();
	else if(ok) sol4();
	else if(n>2000) sol1();
	else sol3();
	return 0;
}
