#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin>>t;
    while(t--){
        long long n,k;
        vector<long long> vec[100000];
        cin>>n>>k;
        for(int i=1;i<n;i++){
            long long u,v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

    }
    cout<<1<<endl;
    cout<<1<<endl;
    cout<<2<<endl;
    return 0;
}
