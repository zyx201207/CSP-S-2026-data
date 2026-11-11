#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N = 5e5+6;
long long n,m,a[N],b[N],c[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a + 1 + n);
    b[n] = 0;
    for(int i = n-1;i >= 1;i--)b[i] = a[n] - a[i];
    c[0] = 0;
    for(int i = 1;i <= n;i++)c[i] = c[i-1] + b[i];
    int L = 1,R = n;
    while(L <= R){
        int mid = (L + R)/2;
        bool f = 0;
        for(int l = 1,r = mid;r <= n;l++,r++){
            //cout << l << " " << r;
            if(c[r-1] - c[l-1] - (mid-1)*b[r] <= m){
                f = 1;break;
            }
        }
        if(f)ans = mid,L = mid+1;
        else R = mid-1;
    }
    cout << ans;
    return 0;
}
