#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define ldb long double
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)

const int N=5e5;
int n;
ll m;
ll a[N+5];
ll qa[N+5];

void solve()
{
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	qa[1]=a[1];
	for(int i = 2;i<=n;i++)qa[i]=qa[i-1]+a[i];
	int ans=0;
	int mid=1;
	for(int i = 1;i<=n;i++)
	{
		while(mid<=i)
		{
			ll tot=1ll*(i-mid+1)*a[i];
			ll now=qa[i]-qa[mid-1];
			if(tot-now>m)mid++;
			else break;
		}
		ans=max(ans,i-mid+1);
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){solve();}
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
