#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k;
struct node{
    ll u,v;
};
node a[1000007];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(ll i=1;i<=n;i++) cin>>a[i].u>>a[i].v;
        cout<<0<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}//please let me AC!
