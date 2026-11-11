#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long c, t, n, x[100000000], d, ans = 0;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w+", stdout);
	cin >> c >> t;
	while(t--){
        ans = 0;
        cin >> n >> d;
        if(n <= 3){
            cout << 0;
            continue;
        }
        for(long long i = 0; i < n; i++){
            cin >> x[i];
        }
        for(long long i = 0; i < n - 3; i++){
            if(x[i + 3] - x[i + 1] <= d && x[i + 2] - x[i] <= d && x[i + 3] - x[i] > d){
                ans ++;
            }
        }
        cout << ans << endl;
	}
	return 0;
}
