#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        if (a[i]+n-1==a[i])
            cout<<a[i];
    }
    return 0;
}
