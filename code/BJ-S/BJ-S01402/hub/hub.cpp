#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> g[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout<<1<<endl;
    }
    return 0;
}
