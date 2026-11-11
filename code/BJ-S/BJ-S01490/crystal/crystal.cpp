#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[500010],sum[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int L=1;
    int ans=0;
    for(int R=1;R<=n;R++){
        while(L<R&&(R-L+1)*a[R]-(sum[R]-sum[L-1])>m){
            L++;
        }
        ans=max(ans,R-L+1);
        //cout << L << " " << R << endl;
    }
    cout << ans;
    return 0;
}
