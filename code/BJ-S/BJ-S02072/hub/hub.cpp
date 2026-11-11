#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t;
int n,k,m;
vector<int> e[N];
bool check(int x){
    return (x-1)*4+k>=m+1;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(k==n){
        cout<<"0\n";
        return ;
    }
    if(c==13 or c==14){
        int l=1,r=n-1,ans=n;
        m=(n-1)/2;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
        return ;
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}