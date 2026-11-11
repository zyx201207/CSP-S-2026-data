#include<bits/stdc++.h>
using namespace std;

void zmjjkk(){
    vector<int >g[200005];
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        g[u].push_back(v);
        g[v].push_back(u);
    }cout<<k/2<<endl;
    return ;
}
int main(){
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        zmjjkk();
    }
return 0;
}
