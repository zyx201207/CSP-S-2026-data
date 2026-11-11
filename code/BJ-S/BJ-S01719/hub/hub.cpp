#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.in","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a,b;
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            cin>>a,b;
            ans=max(ans,b-a);
        }cout<<ans<<endl;
    }
    return 0;
}
