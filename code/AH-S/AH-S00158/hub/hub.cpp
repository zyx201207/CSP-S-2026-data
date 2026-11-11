#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        int m=(n+1)/2;
        m=(m+1)/2;
        m-=(k+1)/2;
        m=(m+1)/2;
        cout<<m+1<<"\n";
    }
return 0;
}
