#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,d,a[5000005],cnt[5005],dis[5005];
vector<ll> adj[5005];
ll bfs(ll s){
    memset(cnt,0,sizeof cnt);
    memset(dis,0x3f,sizeof dis);
    queue<ll> q;
    q.push(s);
    cnt[s]=1;
    dis[s]=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        //cout<<u<<" ";
        for(int i=0;i<adj[u].size();i++){
            ll v=adj[u][i];
            if(!cnt[v]){
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }else if(dis[u]+1==dis[v]){
                cnt[v]+=cnt[u];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
            //cout<<dis[i]<<" ";
        if(cnt[i]==2) ans++;
    }
    //cout<<endl;
    return ans;
}
void solve(){
    ll T;
    cin>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            adj[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        ll ans=0;
        //cout<<1<<endl;
        for(int i=1;i<=n;i++){
            ans+=bfs(i);
        }
        cout<<ans/2<<"\n";
    }
}
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll p=a[1]+d,cnt=0;
    for(int i=2;i<=n;i++){
        if(a[i]<=p) cnt++;
    }
    //cout<<n<<" "<<cnt<<" ";
    if(cnt==0){
        cout<<0<<"\n";
        return ;
    }
    if(n/cnt==3){
        cout<<(n+7)/3<<"\n";
        return ;
    }
    if(cnt==3) cout<<n-5<<"\n";
    else if(cnt==2) cout<<n-3<<"\n";
    else cout<<0<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    if(c<=10){
        solve();
        return 0;
    }
    if(c<=12){
        ll T;
        cin>>T;
        while(T--){
            solve2();
        }
    }
    return 0;
}
