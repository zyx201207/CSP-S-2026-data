#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[1000004];
        int ans=0;
        for(int i=1;i<n*2;i++){
            cin>>a[i];
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
return 0;
}
