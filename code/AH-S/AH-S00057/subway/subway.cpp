#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,m,n,d,q,a[1378][1378],k[1378],t[1378][1378],w[1378],r,l,mn;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=0;i<m;i++){
        cin>>w[i];
    }
    for(ll i=0;i<n;i++){
        cin>>k[i];
        for(ll j=0;j<k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(ll i=0;i<q;i++){
        cin>>l>>r;
        ll he=0;
        he+=(w[l]+w[r]);
        mn=11451419198101145;
        for(ll p=0;p<n;p++){
            for(ll j=1;j<2*k[p];j+=2){
                mn=min(mn,a[p][j]);
            }
            he+=mn;
        }
        cout<<he<<"\n";
    }
    return 0;
}
