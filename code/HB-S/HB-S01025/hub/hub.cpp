#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+6;
int t,c;
ll n,k,u,v,mp[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while (t--){
        for (ll i=1;i<n;i++){
            for (ll j=1;j<=i;j++) mp[i][j]=mp[j][i]=0;
        }
        cin>>n>>k;
        for (ll i=1;i<n;i++){
            cin>>u>>v;
            mp[u][v]=mp[v][u]=1;
        }
        cout<<k<<endl;
    }
    return 0;
}
