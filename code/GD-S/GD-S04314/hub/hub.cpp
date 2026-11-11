#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		int minx = 1e9;
		for(int i = 1;i <= n;i++){
			cin >> u[i] >> v[i];
			minx = min(minx,abs(u[i]-v[i]));
		}
		cout << minx << endl;
	}
	return 0;
}
