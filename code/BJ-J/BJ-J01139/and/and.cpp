#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long  a[n+6];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    x=a[n-1];
    for(int i=2;i<=m;i++){
        x=x&a[n-i];
    }
    cout<<x;
    return 0;
}
