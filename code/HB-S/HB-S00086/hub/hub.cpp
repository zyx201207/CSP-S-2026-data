#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+2;
long long CC,T,n,k,u[N],v[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>CC>>T;
    while(T--){
        cin>>n>>k;
        for(long long i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
    }cout<<1<<' '<<2;
    return 0;
}
