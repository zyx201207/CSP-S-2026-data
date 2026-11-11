
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<n/2-k+1<<endl;
    }
    return 0;
}

