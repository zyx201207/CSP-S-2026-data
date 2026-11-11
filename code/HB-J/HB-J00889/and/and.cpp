#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n,m,a[M],mn;

int main(){
    freopen("and.in","r",std.in);
    freopen("and.out","w",std.out);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin  >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
                mn=max(mn,a[i]&a[j]);
        }
    }cout << mn;

    return 0;
}
