#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
long long n,a[M],tt,cnt,c2;
string c[M];
int main(){
    freopen("string.in","r",std.in);
    freopen("string.out","w",std.out);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
    for(int i=1;i<=n;i++){
        if(c[i]==c[1]) tt=0;
        else {
            cnt+=a[i];
            c2+=a[i];
        }
    }tt=max(cnt/2,c2);
    cout << tt;

    return 0;
}
