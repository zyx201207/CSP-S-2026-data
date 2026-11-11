#include <bits/stdc++.h>
using namespace std;
int c, t, f;
int n, d;
int a[2000010], b[2000010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
	    for(int i = 2;i <= n;i++){
	    	if(a[i] - a[i - 1] != 1){
	    		f = 1;
	    	}
	    }
	    if(f == 0){
	    	cout << n - d - 1 << endl;
	    }else{
	    	cout << 0 << endl;
	    }
	}
	return 0;
}
