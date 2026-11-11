#include<bits/stdc++.h>
using namespace std;
int a[200005],b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b=a[n];
    for(int i=1;i<=m;i++){
        b=b&a[n-1];
    }
    cout<<b;
    return 0;
}
