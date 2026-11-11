#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n,j=1;j<=m;i--,j++){
        a[i-1]=a[i]&a[i-1];
    }
    cout<<a[n-m+1];
    return 0;
}
