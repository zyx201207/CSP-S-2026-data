#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000010];
int main(){
    cin.tie(0),ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            vector<int>sum(n+1,0),vis(n+1,1e9);
            queue<ll>q;
            q.push(i);
            vis[i]=0;
            while(!q.empty()){
                int k=q.front();
                // cout<<k<<"\n";
                q.pop();
                sum[k]++;
                for(int j=k+1;a[j]-a[k]<=d&&j<=n;j++){
                    // cout<<k<<" "<<j<<"\n";
                    if(vis[k]+1<=vis[j])vis[j]=vis[k]+1,q.push(j);
                }
            }
            for(int j=i;j<=n;j++){
                if(sum[j]==2)ans++;
                // cout<<vis[j]<<" ";
            }
            // cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}