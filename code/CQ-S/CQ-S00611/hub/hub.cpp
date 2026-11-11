#include <bits/stdc++.h>
using namespace std;
const int N=2000006;
int c,t,k,n;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		int u,v;
		for(int i=1;i<n;i++) cin >> u >> v;
		int m=(n-1)/2;
		if(k==n){
			cout << "0\n";
			continue;
		}
		if(k>=m+1){
			cout << "1\n";
			continue;
		}
		if(m%2==1){
			if(((k-1)/2)%2==1) cout << ((m-1)/2)/2+1 << "\n";
			else cout << ((m-1)/2)/2 << "\n";
		}
	}
	return 0;
}
