#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int a[N];
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d/(a[2]-a[1])==1)cout<<0<<'\n';
		else cout<<n-d/(a[2]-a[1])*2+1<<'\n';
	}
	return 0;
}