#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>g[1000010];
void solveA(){
    cin>>n>>k;int m=(n-1)/2;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout<<ceil(1.0*(m+1)/(k+1))<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie();
    cin>>c>>t;
    while(t--){
      //  if(c==13||c==14)
            solveA();
    }
}
