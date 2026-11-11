#include<bits/stdc++.h>
using namespace std;
const int N=2e6+8;
int n,k;
vector<int> V[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            V[u].push_back(v);
            V[v].push_back(u);
        }
        
    }
    return 0;

}