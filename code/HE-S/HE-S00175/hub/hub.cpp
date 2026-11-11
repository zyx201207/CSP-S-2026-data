#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
    cin>>n>>m;
    cout<<1;
    for(int i=1;i<=n;i++){
        cout<<2<<"\n";
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}
