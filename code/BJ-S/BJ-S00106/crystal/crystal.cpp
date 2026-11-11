#include<bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 10;
int n, ans;
long long m, a[mxn];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    long long sum = 0;
    int i = 1, j = 1, cnt = 0;
    for( ; i <= n; ){
        //cerr << i << " " << j << endl;
        //cerr << sum << endl;
        if(sum <= m) ans = max(ans, j - i + 1);
        if(sum <= m && j != n && a[j+1]-a[j] == 0){
            j++;
            sum += (a[j] - a[j-1]) * (j - i);
        }
        else if(sum < m && j != n){
            j++;
            sum += (a[j] - a[j-1]) * (j - i);
        }
        else{
            if(cnt == 0 && j != n){
                j++;
                sum += (a[j] - a[j-1]) * (j - i);
                cnt = 1;
            }
            i++;
            sum -= (a[j]-a[i-1]);
            cnt = 0;
        }
    }
    if(sum <= m) ans = max(ans, j - i + 1);
    cout << ans << endl;
    return 0;
}
