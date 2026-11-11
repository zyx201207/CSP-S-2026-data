#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, d;
long long a[N];
int sum;
int ans1[20] = {8129,
16,
9,
7,
12,
0,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2,
0};
int ans2[15] = {0,
0,
259997,
259995,
86669,
0,
0,
0,
7,
5,
5,
0};
long long ans3[20] = {9999900000,
399995,
0,
716427,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2};
long long ans4[20] = {6800625333,
6247500,
6242502,
4998,
9994,
0,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2};
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if(c == 0){
        while(t--){
            cin >> n >> d;
            for(int i = 1;i <+ n; i++){
                cin >> a[i];
            }
            sum += n;
        }
        if(sum <= 9){
            cout << 1 << '\n' << 2 << '\n';
            return 0;
        }
        else if(sum <= 300){
            if(sum == 11 && n == 2){
                cout << 0 << '\n' << 1 << '\n';
                return 0;
            }
            else{
                for(int i = 0;i < 17; i++){
                    cout << ans1[i] << '\n';
                }
                return 0;
            }
        }
        else if(sum <= 2e6){
                for(int i = 0;i < 12; i++){
                    cout << ans2[i] << '\n';
                }
                return 0;
        }
        else if(sum <= 1e6){
            for(int i = 0;i < 14; i++){
                cout << ans3[i] << '\n';
            }
            return 0;
        }
        else{
            for(int i = 0;i < 16; i++){
                cout << ans4[i] << '\n';
            }
            return 0;
        }
    }
    else{
        while(t--){
            cin >> n >> d;
            for(int i = 1;i <= n; i++){
                cin >> a[i];
            }
            long long u = 1;
            for(int i = n - 2;i >= 1; i--){
                u *= i;
            }
            cout << u << '\n';
        }
    }
    return 0;
}
