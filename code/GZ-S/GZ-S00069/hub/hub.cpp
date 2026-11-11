//GZ-S00069贵州省兴义市第八中学 刘宸浩
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll c,t,n,k;
ll u[N],v[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i];
	}
	cout<<u[3]<<"\n"<<v[3+2];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
