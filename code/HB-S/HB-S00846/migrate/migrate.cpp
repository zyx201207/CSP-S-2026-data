#include <bits/stdc++.h>

using namespace std;

const int M = 2e6 + 10;
int c, n, a[M], b, d, total, cnt;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> n;
    while(n--){
        cin >> b >> d;
        for(int i = 1; i <= b; i++) cin >> a[i];
        for(int i = 1; i <= b; i++){
            for(int j = 1; j <= d; j++){
                if((a[i] + j - i) - j >= j ||(a[i] + j - i) - j == 0) total++;
                if(total > 2 || total < 0){
                    total = 0;
                }
            if(total == 2) cnt++;
            }
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}
