#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n,m,ans;
int a[500010],qsum[500010];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++){
        qsum[i] = qsum[i-1] + a[i];
    }
    int L = 1,C = 0;
    for (int i = 2;i <= n;i++){
        C += (i-L)*(a[i]-a[i-1]);
        while (C > m){
            L++;
            C -= (a[i] - a[L]);
        }
        ans = max(ans,i-L+1);
    }
    cout << ans;
    return 0;
}
