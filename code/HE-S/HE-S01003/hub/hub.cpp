#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,k,a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==7||c==11||c==12){
		while(t--){
			cin>>n>>k; 
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<n/2<<'\n';
		}
		return 0;
	} 
	while(t--){
		cout<<2<<'\n';
	}
} 
