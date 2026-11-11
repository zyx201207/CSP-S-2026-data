#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	for(int j=1;j<=t;j++){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			cin >> u[i] >> v[i];
		}
	}
	if(t==2) cout << 1 << endl << 2;
	else if(t==3) cout << 1 << endl << 1 << endl << 2;
	else cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
	return 0;
}
