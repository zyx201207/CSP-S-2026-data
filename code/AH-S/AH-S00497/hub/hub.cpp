#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int c,t;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<(k+1)/2<<'\n';
    }
    return 0;
}