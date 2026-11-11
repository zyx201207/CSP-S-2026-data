#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)
    int n,m,a[200010]={},maxa=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            maxa=max(maxa,a[i]&a[j]);
        }
    }
    cout<<maxa;
    return 0;
}