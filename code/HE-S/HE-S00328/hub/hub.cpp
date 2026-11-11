#include<bits/stdc++.h>
using namespace std;
int c,t;
signed main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		int x,y;
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>x>>y;
		cout<<n-1<<"\n";
	}
	return 0;
}

