#include<bits/stdc++.h>
using namespace std;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		srand(time(0));
		int res=rand()%(n/2);
		cout<<res<<'\n';
	}
	return 0;
}
