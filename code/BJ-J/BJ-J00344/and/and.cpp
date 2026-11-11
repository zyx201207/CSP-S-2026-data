#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long c[1005],a[1005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }sort(c+1,c+n+1);
    for(int i=1;i<=m;i++){
        a[i]=c[i];
    }
    cout<<a[1];
    return 0;
}