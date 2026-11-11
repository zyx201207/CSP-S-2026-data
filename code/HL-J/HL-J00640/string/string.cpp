#include <bits/stdc++.h>
using namespace;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int cnt = 0;
    cin << n;
    for(int i=0;i<=n;i++){
        cin << a << b;
        c += a*b;
    }
    d = reverse(c);
    for(int i=0;i<size(c);i++){
        if(c[i]!=d[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
