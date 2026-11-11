#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,x,y;
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>x>>y;
		cout<<(n-k)/8+1+((n-k)%8!=0)<<endl;
	}
	return 0;
}

