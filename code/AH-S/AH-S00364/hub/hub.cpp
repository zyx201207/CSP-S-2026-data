#include<bits/stdc++.h>
using namespace std;
int C,T,n,k;
vector<int> g[2000005];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==k){
            cout<<0<<endl;
            continue;
        }
        int m=(n-1)/2;
        if(m<=k){
            cout<<1<<endl;
            continue;
        }
        for(int i=0;i<=n;i++){
            int x=i,y=m-i+1;
            x+=k/2,y-=k/2;
            if(k%2==1)y--;
            if((y-x-1+1)/2+1<=i){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
//Oct31==Dec25?
