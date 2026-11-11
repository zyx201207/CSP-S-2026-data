#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<int> p;
};
Node a[10000];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        a[u].p.push_back(v);
        a[v].p.push_back(u);
    }
    cout<<n-k;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;   
}


