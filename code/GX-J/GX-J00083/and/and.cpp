#include <bits/stdc++.h>
using namespace std;
const long long N=10000;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[N],m,n,ands=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n);
    ands+=(a[0] and a[1]);
    for(int i=2;i<=n;i++){
        ands*=(ands and a[i]);
    }
    cout<<ands;
    return 0;
}
