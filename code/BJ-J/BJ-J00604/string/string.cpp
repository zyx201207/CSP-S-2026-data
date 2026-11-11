#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,a[200005],x1,x2,m1,m2,sum,k;
char b[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    m1=1,m2=n,x1=1,x2=1;
    while (m1<m2){
        k = min(a[m1]-x1,a[m2]-x2)+1;
        if (b[m1]!=b[m2]) ans += k;
        x1+=k,x2+=k;
        if (x1>a[m1]){
            m1++;
            x1=1;
        }
        if (x2>a[m2]){
            m2--;
            x2=1;
        }
    }
    cout << ans;
    return 0;
}