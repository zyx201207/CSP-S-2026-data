#include<bits/stdc++.h>
using namespace std;

long long n , m;
long long a[500005] , ans = 0;



int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);

    cin >> n >> m;
    for (int i = 1;i <= n;i++)cin >> a[i];
    sort(a+1 , a+n+1);
    //cout << 1 << "\n";

    for (int i = 1;i <= n;){
        for (int j = i;j <= n;j++){
            if(a[j+1] != a[i]){
                long long x = j-i+1;
                long long p = m;
                //cout << "now " << a[i] << ":\n";
                //string s = to_string(x) + " " + to_string(i) + " " + to_string(j) + "\n";
                for (int k = i-1;k >= 1;k--){
                    if(p < 0){
                        x--;
                        break;
                    }
                    x++;
                    p -= a[i]-a[k];
                    //s += to_string(x) + " " + to_string(a[k]) + " " + to_string(a[i]-a[k]) + " " + to_string(p) + "\n";
                    //cout << "   find: " << a[k] << " cha: " << a[i]-a[k] << "\n";
                    //if(x == 3)cout << k << " " << i << " " << j << "\n" << s << "\n";
                }

                ans = max(ans , x);
                i = j+1;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
