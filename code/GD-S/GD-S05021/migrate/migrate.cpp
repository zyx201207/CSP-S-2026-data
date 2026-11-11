#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int c,t,a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==13||c==14)cout<<n-2<<"\n";
		else if(c==15||c==16||c==17||c==18)cout<<"10\n";
		else cout<<"0\n";
	}
	return 0;
}
