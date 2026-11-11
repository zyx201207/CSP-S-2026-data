#include <bits/stdc++.h>
using namespace std;
int a[11111111];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, w, n, m;
	cin >> c >> w;
	while(w--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		cout << n-m-m << endl;
	}
	return 0;
}
