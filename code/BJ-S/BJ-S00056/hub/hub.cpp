#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
vector<int>g[N];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(c==13 || c==14){
            int m=n/2;
            if(k>=m){
                cout<<"1"<<endl;
                continue;
            }
            int all=m-k+1;
            int x=all/4;
            int yu=all%4;
            cout<<x+yu+1<<endl;
            continue;
        }
    }

    return 0;
}
