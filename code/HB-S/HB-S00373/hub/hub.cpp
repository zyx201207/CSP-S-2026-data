#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<(n/k+1)<<"\n";
    }
    return 0;
}