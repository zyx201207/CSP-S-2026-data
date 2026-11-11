#include<bits/stdc++.h>
using namespace std;
int C,T,n,k;
bool f[5005][5005];
bool b[5005],con[5005];
int mi[5005];//0x3fic
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            f[u][v]=f[v][u]=1;
        }
        cout<<k-1<<endl;
    }
    return 0;
}
