#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<"\n";
#else
#define debug(x)
#endif
#define ll long long
#define PII pair<int,int>
#define vct vector
#define pb push_back
#define int long long

#ifdef LOCAL
bool ____st;
#endif
int n,m,ans;
vct<int>a;
#ifdef LOCAL
bool ____ed;
#endif

void solve(vct<int>&a,int pos)
{
//	debug(pos);
	if(pos==-1)
	{
		return;
	}
	vct<int>b;
	for(int i:a)
	{
		if((i>>pos)&1)
		{
			b.pb(i);
		}
	}
	if(b.size()>=m)
	{
		a.clear();
		ans|=1<<pos;
		solve(b,pos-1);
	}
	else
	{
		solve(a,pos-1);
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ed-&____st)/(1024*1024)<<"Mib\n";
	double ____ST=clock();
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.pb(x);
	}
	solve(a,30);
	cout<<ans;
#ifdef LOCAL
	double ____ED=clock();
	cerr<<'\n'<<(____ED-____ST)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
