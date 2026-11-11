#include <bits/stdc++.h>
using namespace;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n ,m,a[200010],c[200010];
    cin << n << m;
    for(int i=0;i<m;i++){
        cin << b;
        a[i] = b;
    }
    for(int j=0;j<m;j++){
        if(a[j]>1){
            c[j] += a[j]%2;
        }
    }
    cout << max(c);
    return 0;
}
