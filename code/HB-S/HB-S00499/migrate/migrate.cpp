#include<bits/stdc++.h>
using namespace std;
long long a[2000009] = {};
int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);

    long long c , t , n , d;
    cin >> c >> t;
    for(long long i = 1;i <= t;i++){
        cin >> n >> d;
        for(long long j = 1;j <= n;j++){
            cin >> a[j];
        }
        if(d >= (a[2] - a[1]) * 2 && d <= (a[n] - a[1])){
			long long aa = d / (a[2] - a[1]) , ans = 0; 

			for(int j = aa;j >= 2;j -= 2){
                ans += aa + 1;
            }
            ans += ans * (n - aa);
            cout << ans << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
