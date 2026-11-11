#include<bits/stdc++.h>
using namespace std;
const int N=1e6+13267;
int c,t,n,k,u,v;
vector<int>vec[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        cout<<n/k-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
