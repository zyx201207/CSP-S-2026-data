#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[1000005],v[1000005];
void solve1(){
    cin>>n>>k;
    for(int i=1;i<n;i++) cin>>u[i]>>v[i];
    cout<<(n+4-2*k)/8+1<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--) solve1();
    return 0;
}
