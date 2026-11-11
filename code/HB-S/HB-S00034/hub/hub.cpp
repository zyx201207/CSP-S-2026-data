#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        for (int i=1,u,v;i<n;i++)cin>>u>>v;
        if (k%2)cout<<(k+1)/2-1<<'\n';
        else cout<<k/2<<'\n';
    }
    return 0;
}