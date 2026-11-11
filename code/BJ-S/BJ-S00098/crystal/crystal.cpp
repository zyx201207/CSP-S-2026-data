#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans;
int a[500005],sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l = 1,r = i,x = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
                r = mid-1;
                x = mid;
            }
            else{
                l = mid+1;
            }
        }
//        cout << i << " " << x << endl;
        ans = max(ans,i-x+1);
    }
    cout << ans;
    return 0;
}
