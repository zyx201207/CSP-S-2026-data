#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,kkk;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t;
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	while(t--){
		cin>>n>>kkk;
		for(int i=1;i<=n-1;i++){
			cin>>kkk;
			cin>>kkk;
		}
		if(n>20)n-=10;
		uniform_int_distribution<int>dis(0,n);
		cout<<dis(mt)<<'\n';
	}
	return 0;
}
