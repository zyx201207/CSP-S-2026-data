#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    int n,d;cin>>n>>d;
    int a[n];
    int ans=0;
    for (int i=0;i<=n;i++){
        if (a[i]-a[j]<=0&&d>=0){
            cin>>a[i]-a[j];
        }
        if (a[i]-a[j]==0){
            cout<<ans;
        }
    }
    return 0;
}

