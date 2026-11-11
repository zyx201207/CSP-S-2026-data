#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(long long i=0;i<n;++i){
            long long u,v;
            cin>>u>>v;
        }
        cout<<n-k+1<<'\n';
    }
    return 0;
}
