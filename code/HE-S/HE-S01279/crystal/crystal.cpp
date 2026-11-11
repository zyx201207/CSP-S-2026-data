#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,m;
int ans;
ll a[maxn],pre[maxn],b[maxn];
queue<int> q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		pre[i]=pre[i-1]+(a[i]-a[i-1]);
		b[i]=a[i]-a[i-1];
	}
	ll now=0;
	for(int i=1;i<=n;i++)
	{
		now+=1ll*q.size()*b[i];
		while(now>m)
		{
			int op=q.front();
			q.pop();
			now-=pre[i]-pre[op];
		}
		q.push(i);
		ans=max(ans,(int)q.size());
	}
	cout<<ans<<'\n';
	return 0;
}
