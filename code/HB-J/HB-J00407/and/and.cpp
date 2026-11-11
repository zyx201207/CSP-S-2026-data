#include <bits/stdc++.h>
using namespace std;
int a[200009];
int ans;
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[i]&a[j]>ans) ans=a[i]&a[j];
        }
    }
    cout<<ans;
    return 0;
}
