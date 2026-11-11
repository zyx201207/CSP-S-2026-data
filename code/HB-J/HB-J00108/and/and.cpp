#include<bits/stdc++.h>

using namespace std;

long long n,m,a[200050];

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=n; i>n-m; i--){
        a[n]=a[n]&a[i];
    }
    cout<<a[n];

    return 0;
}
