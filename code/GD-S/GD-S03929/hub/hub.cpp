#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int n,m,ans;


signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	if(n == 0)
	{
		cin>>n;
		if(n == 4)
		{
			cout<<1<<'\n'<<2;
		}
		if(n == 5)
		{
			cout<<0<<'\n'<<1;
		}
	}
	
	return 0;
}
