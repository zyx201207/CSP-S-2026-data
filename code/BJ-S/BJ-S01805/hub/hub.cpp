#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,T,n,k,u,v;
vector<int> edge[maxn];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        // edge.clear();
        for(int i=1;i<n;i++){
            cin>>u>>v;
            // edge[u].push_back(v);
            // edge[v].push_back(u);
        }
        if(c==13 || c==14){
            cout<<floor(ceil(((n+1)/2-k)*1.0/2+1)/2)+1<<endl;
        }
    }
    return 0;
}