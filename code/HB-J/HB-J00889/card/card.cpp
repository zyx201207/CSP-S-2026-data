#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int n,m,a[M],f[M],ans[M];
int main(){
    freopen("card.in","r",std.in);
    freopen("card.out","w",std.out);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){

        f[M]={};
        for(int j=1;j<=n;j++){

            if(a[i]==f[j]) {
                f[M]={};
                f[i]=a[i];
            }else a[i]=f[i];
        }for(int j=1;j<=n;j++) ans[f[j]]++;
    }for(int i=1;i<=n;i++) cout << ans[i];

    return 0;
}
