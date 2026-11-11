#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
void solve()
{
	int n,d;
	cin>>n>>d;
	ll Cyrene=0,ai[N];
	for(int i=1;i<=n;i++) cin>>ai[i];
	Cyrene=n/d-1;
	cout<<Cyrene<<'\n';
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
} 
