#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main (){
    freopen ("card.in","r",std.in);
    freopen ("card.out","w",std.out);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n-1;i++ ){
        for (int j=1;j<4999;j++){
            a[i]!=a[i-1];
        }
    }
return 0;
}
