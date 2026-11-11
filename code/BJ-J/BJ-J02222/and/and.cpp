#include <bits/stdc++.h>
using namespace std;
int a[200010];
int and(n){
    int sum=-1;
    for ( int i=n;i>0;i-- ) {
        if ( a[i]>=m ) {
            sum=i;
            break;
        }
    }
    if ( sum=-1 ) return 0;
    return pow(2,sum)+and(sum-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num[31];
    cin >> n >> m;
    for ( int i=1;i<=n;i++ ) {
        cin >> a[i];
        for ( int i=1;t;i++ ){
            num[i]+=t%2;
            t/=2;
        }
    }
    cout << and(30);
    return 0;
}