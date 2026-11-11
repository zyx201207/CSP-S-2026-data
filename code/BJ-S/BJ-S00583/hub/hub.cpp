#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
//rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int m=(n-1)/2;
        if(k>=n) cout<<0<<'\n';
        else if(k>=m) cout<<1<<'\n';
        else cout<<(m+3-k+3)/4<<'\n';
    }
    return 0;
}
