#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll c,t,n,k;
vector<int> g[maxn];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int u,v;
        for(int i=1;i<=n-1;++i){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==1) cout<<n/4+1<<endl;
        //else if(k==2) cout<<n/6+1;
        else if(k<n/2) cout<<(n/2+3-k)/4+1<<endl;
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}
//10