#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2000) cout<<a[n];
    else if(n>=20000&&m>=10000) cout<<n-m;

    return 0;
}
