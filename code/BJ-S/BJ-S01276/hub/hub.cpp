#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[2000050];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int p=n/2+2;
        if(k==1){
            if(p&1)cout<<(p-k)/2<<'\n';
            else cout<<(p-k+1)/2<<'\n';
        }else{
            if(p%2==0){
                k=k-k%2;
                cout<<(p/2-k/2)/2<<"\n";
            }else{
                p++;
                k=k+k%2;
                k/=2;
                if((k/2)&1){
                    k--;
                }
                cout<<(p/2-k/2)/2<<"\n";
            }
        }
    }
    return 0;
}