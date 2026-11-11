#include<bits/stdc++.h>
using namespace std;
namespace rp{
    void slow() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    void main() {
        //slow();
        int c;cin>>c;
        int T;cin>>T;while(T--) {
            int n,kk;cin>>n>>kk;
            if(kk==n) {
                for(int i=1,u,v;i<n;i++)cin>>u>>v;
                cout<<0<<'\n';
                continue;
            }
            for(int i=1,u,v;i<n;i++)cin>>u>>v;
            cout<<1;
            cout<<'\n';
        }
    }
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    rp::main();
}
