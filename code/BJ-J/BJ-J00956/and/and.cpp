#include <bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,nd=2147483647,nd2=2147483647,nd3=2147483647;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        nd=(nd&a[n-i+1]);
    }
    for(int i=1;i<=m;i++){
        nd2=(nd2&a[n-i]);
    }
    for(int i=1;i<=m;i++){
        nd3=(nd3&a[n-i-1]);
    }
    cout<<max(nd,max(nd2,nd3));
    return 0;
}
