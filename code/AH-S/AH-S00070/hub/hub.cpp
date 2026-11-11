#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int> q[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            q[u].push_back(v);
            q[v].push_back(u);
        }
        cout<<((n+1)-k*2)/8+1<<"\n";
    }
    return 0;
}
