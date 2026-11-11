#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t;
int n,d;
ll a[N];
int s;
ll mindist=1e18;
void dfs(ll u,ll v,ll dist){
    if(u>v) return;
    if(dist>mindist) return;
    if(u==v){
        if(dist==mindist){
            s++;
        }
        mindist=min(mindist,dist);
        return;
    }
    dfs(u+1,v,dist+1);
    dfs(u+d,v,dist+1);

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                mindist=1e18;
                s=0;
                dfs(a[i],a[j],0);
                if(s==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

