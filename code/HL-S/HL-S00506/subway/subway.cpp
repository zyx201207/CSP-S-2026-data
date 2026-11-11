#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[10000000];
long long ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> a[i];
        ans+=a[i];
    }
    cout << ans;
    return 0;
}
