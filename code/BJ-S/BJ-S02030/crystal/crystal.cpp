#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005], c[500005][2];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, ans=1, l, r, j;
    long long m, t;
    cin >> n >> m;
    for (int i=1; i<=n; ++i){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i=2; i<=n; ++i){
        b[i]=a[i]-a[i-1];
        c[i][0]=(c[i-1][0]+(i-1)*b[i])%1000000000000;
        c[i][1]=c[i-1][1]+(c[i-1][0]+(i-1)*b[i])/1000000000000;
        l=0, r=i-2;
        while (l<=r){
            j=(l+r)/2;
            if (c[i][1]-c[j+1][1]>m/1000000000000){
                l=j+1;
                continue;
            }
            t=(c[i][1]-c[j+1][1])*1000000000000+c[i][0]-c[j+1][0]-j*(a[i]-a[j+1]);
            if (t>m) l=j+1;
            else{
                ans=max(ans, i-j);
                r=j-1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}