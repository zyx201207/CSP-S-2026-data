
#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int u,v;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>u>>v;
        }
        cout<<(n+k)/2<<endl;;
    }
}
