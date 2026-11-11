#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n+1);
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }*/
    cout<<a[n-m+1];
    return 0;
}
