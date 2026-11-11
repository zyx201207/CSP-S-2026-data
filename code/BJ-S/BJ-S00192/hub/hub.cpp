#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>ans>>ans;
    cout<<(n-m+3)/4<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
