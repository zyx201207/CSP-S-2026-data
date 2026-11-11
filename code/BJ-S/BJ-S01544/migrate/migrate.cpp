#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000005],L[2000005],R[2000005],dis[2000005],cnt[2000005];
struct node{
    int u,w;
};
vector<node> adj[2000005];
deque<node> q;
void dij(int s){
    for(int i=1;i<=n;i++){
        dis[i]=1e18,cnt[i]=0;
    }
    dis[s]=0;cnt[s]=1;
    q.push_back({s,0});
    while(!q.empty()){
        int u=q.front().u,w=q.front().w;
        q.pop_front();
        if(dis[u]!=w) continue;
        for(int i=0;i<adj[u].size();i++){
            int x=adj[u][i].u,v=adj[u][i].w;
            if(dis[x]>dis[u]+v){
                dis[x]=dis[u]+v;
                cnt[x]=cnt[u];
                if(v==0) q.push_front({x,dis[x]});
                else q.push_back({x,dis[x]});
            }
            else if(dis[x]==dis[u]+v) cnt[x]+=cnt[u];
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T,d;
    cin>>C>>T;
    while(T--){
        //init;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int l=i,r=n,loc;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[mid]-a[i]<=d){
                    loc=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            R[i]=loc;
            l=1,r=i;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[i]-a[mid]<=d){
                    loc=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            L[i]=loc;
        }
        if(C<=10){
            for(int i=1;i<=n;i++) adj[i].clear();
            for(int i=1;i<=n;i++){
                adj[i].push_back({R[i],1});
            }
            int ans=0;
            for(int i=n;i>=1;i--){
                dij(i);
                adj[i].push_back({i-1,0});
                for(int j=i+1;j<=n;j++){
                    if(cnt[j]==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        if(C<=12){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(R[i]==n||R[i]==i) continue;
                int tmp=R[i]-i;
                if(tmp==1) continue;
                if(i+tmp+tmp-1<=n) ans++;
            }
            cout<<ans<<'\n';
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int t1=R[i],t2=R[t1-1];
            if(i==t1||t1==t2) continue;
            int l=t1+1;
            l=max(l,R[t1-2]+1);
            if(l<=t2) ans+=t2-l+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
