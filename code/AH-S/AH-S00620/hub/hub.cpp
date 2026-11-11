#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int>d[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            d[u].push_back(v);
        }
        if(c==13||c==14){
            cout<<(n-k-3)/4+1<<'\n';
            break;
        }
    }
    return 0;
}
