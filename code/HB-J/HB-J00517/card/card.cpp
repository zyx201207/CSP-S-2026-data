#include <bits/stdc++.h.
using namespace std;
int main(
    freopen("cart.in","r",stdin);
    freopen("cart.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]=0,o[n]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1])
            o[i]=a[i];
    }
    cout<<o[n];
    return 0;
)
