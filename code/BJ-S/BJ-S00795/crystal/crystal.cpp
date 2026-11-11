#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N + 1];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + 1 + n);
    int ans = 0;
    __int128 sum = 0;
    for(int i = 1,j = 0;i <= n;i++){
        while(j < n && (__int128)a[j + 1] * (j - i + 2)
        - (sum + a[j + 1]) <= m)
            j++,sum += a[j];
        ans = max(ans,j - i + 1);
        sum -= a[i];
    }
    cout<<ans<<"\n";
}
