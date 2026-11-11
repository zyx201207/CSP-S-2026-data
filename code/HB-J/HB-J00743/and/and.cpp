#include <bits/stdc++.h>
using namespace std;
int m,n,a[100001],ans;
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    ans=a[m];
    for(int i=1;i<n;i++){
        ans&=a[m-i];
    }
    cout<<ans;
    return 0;
}
