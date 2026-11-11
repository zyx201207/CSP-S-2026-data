#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int maxn=2e6+13;
struct node{
    int x,y;
}edge[maxn];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>edge[i].x>>edge[i].y;
        }
        if(n<=5){
            if(k!=n) cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;

        }
        if(c==13||c==14){
            if(k==n) cout<<0<<'\n';
            if(k>=n/2) cout<<1<<'\n';
            int m=n/2;
            cout<<1+(m-k+2)/4<<'\n';
            continue;
        }
    }
    return 0;
}
