#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define int __int128
const int N=1e6,A=1e18;
int c,t,n,k,u,v;
signed main()
{
	freopen("hub4.in","r",stdin);
	//freopen(".out","r",stdin);
	//freopen(".in","w",stdout);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		cout<<k-1<<"\n";
	}
	return 0;
}

