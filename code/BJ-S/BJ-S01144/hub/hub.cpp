#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> G[N];
int n,m,k;
bool flag_A=true;
bool A(){
    return flag_A;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        m=(n-1)/2;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            if(1<=i && i<=m){
                if(u!=i || v!=i+1){
                    flag_A=false;
                }
            }
            else if(m+1<=i && i<=n-1){
                if(u!=i-m || v!=i+1){
                    flag_A=false;
                }
            }
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(k==n){
            cout<<0<<endl;
            continue;
        }
        if(A){
            if(k>=m){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<(m+2+2*k-1)/(2*k)<<endl;
                continue;
            }
        }
    }
    return 0;
}