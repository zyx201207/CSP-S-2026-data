#include<bits/stdc++.h>
using namespace std;
long long n,d,minn=1e18;
long long c,t,x[2000005],ans;
map<int,int> g,dis,cnt;
void bfs(int s){
    queue<int> q;
    q.push(s);
    for(int i=minn;i<=n;i++){
        dis[i]=-1;
        cnt[i]=0;
    }
    dis[s]=0;
    while(!q.empty()){
        int y=q.front();
        q.pop();
        for(int i=y-d;i<=y+d;i++){
            if(i<minn||i>n||g[i]==0) continue;
            if(dis[i]==dis[y]+1) cnt[i]++;
            if(dis[i]==-1){
                q.push(i);
                dis[i]=dis[y]+1;
                cnt[i]++;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) minn=min(minn,x[i]);
        for(int i=minn;i<=n;i++) g[i]=0;
        for(int i=1;i<=n;i++) g[x[i]]=1;
        if(c==11||c==12){
            int p=x[2]-x[1];
            if(d>=2*p) cout<<n-3<<endl;
            else cout<<0<<endl;
            continue;
        }
        if(c==13||c==14){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            bfs(x[i]);
            int y=0;
            for(int i=minn;i<=n;i++){
                if(cnt[i]==2) y++;
            }
            ans+=y;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
