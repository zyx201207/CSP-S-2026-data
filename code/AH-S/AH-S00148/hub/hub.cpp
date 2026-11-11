#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n-1;i++){
            int ui,vi;
            cin>>ui>>vi;
        }
        cout<<(int)(ceil(n*1.0/d))/2<<'\n';
    }
    return 0;
}
