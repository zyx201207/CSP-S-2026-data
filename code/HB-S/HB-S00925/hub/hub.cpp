#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int c,t,n,k,u[2000005],v[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        For(i,1,n-1)cin>>u[i]>>v[i];
    }
    return 0;
}
