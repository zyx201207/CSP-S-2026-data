#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005];
vector<int>G[5005];
int dis[5005],cnt[5005];
bool inq[5005];
int countans(int st){
    for(int i=1;i<=n;i++) dis[i]=1e18,cnt[i]=0,inq[i]=0;
    queue<int>q;
    cnt[st]=1;
    dis[st]=0;
    inq[st]=1;
    q.push(st);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(auto v:G[u])
            if(dis[v]>=dis[u]+1){
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    cnt[v]=0;
                    if(!inq[v]){
                        q.push(v);
                        inq[v]=1;
                    }
                }
                cnt[v]+=cnt[u];
            }
    }
    int res=0;
    for(int i=st+1;i<=n;i++) res+=(cnt[i]==2);
    return res;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c<=10){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i],G[i].clear();
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(a[j]-a[i]<=d) G[i].push_back(j);
            int ans=0;
            for(int i=1;i<=n;i++) ans+=countans(i);
            cout<<ans<<"\n";
        }else if(c==11||c==12){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            int dis=a[2]-a[1],p=d/dis;
            if(p<2) cout<<0<<"\n";
            else cout<<max(n-2*p+1,0ll)<<"\n";
        }
    }
    return 0;
}