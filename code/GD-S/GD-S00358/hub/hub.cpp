#include<bits/stdc++.h>
using namespace std;
int c,g,n,k,x;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>g;
	while(g--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>x>>x;
		cout<<k-1<<'\n';
	}
	return 0;
}
