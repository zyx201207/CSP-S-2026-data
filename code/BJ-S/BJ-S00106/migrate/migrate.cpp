#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int mxn = 2e6 + 10;
int c, t;
long long a[mxn], b[mxn], p[mxn];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        memset(b, 0, sizeof(b));
        long long n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i > 1){
                p[i-1] = a[i] - a[i-1];
            }
        }
        long long ans = 0, sum = p[1];
        for(int i = 1, j = 1; i <= n-1; ){
            //cerr << i << " " << j << " " << sum << endl;
            if(sum == d){
                if(b[i] > 0) ans += b[i];
                b[j]++;
            }
            if(sum < d && j != n-1){
                j++;
                sum += p[j];
            }else{
                i++;
                sum -= p[i-1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
