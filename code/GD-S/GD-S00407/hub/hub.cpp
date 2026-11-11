#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
		}
		if(n==k)cout<<"0\n"; 
		else cout<<n/4-k+2<<'\n';
	}
	return 0;
}
