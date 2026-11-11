#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}
		int m=(n-1)/2;
		cout<<(m-k)/k<<'\n';
	}
	return 0;
}
