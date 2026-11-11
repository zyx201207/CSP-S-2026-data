#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n,k,u,v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a[n+5];
        for(int i=1;i<n;++i){
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }
    return 0;
}
