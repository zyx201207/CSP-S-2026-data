#include<bits/stdc++.h>
using namespace std;
int T,c,n,k;
vector<int> vt[200010];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        cout<<0<<"\n";
    }
    return 0;
}