#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int c,t;
int n,k;
int ma[105][105];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            ma[u][v]=1;
            ma[v][u]=1;
        }
    }
    return 0;
}
