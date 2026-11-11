#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1001]={},b[1001]={},cnt;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sort(a[i],a[i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i] and a[i-1];
        for(int j=1;j<=m;j++){
            cnt=max(max(b[i],b[i-1]),cnt);
        }
    }
    cout<<cnt;
    return 0;
}
