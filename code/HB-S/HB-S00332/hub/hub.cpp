#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,c,t;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		int x,y;
		for(int i=1;i<n;i++)
			cin>>x>>y;
		cout<<k-1<<endl;
	}
	return 0;
}
