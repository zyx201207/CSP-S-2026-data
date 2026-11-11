#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+7;

int n,vis[N],s[N];
ll x[N],d,ans,dis[N];
queue<pair<int,int> >q;

void bfs(int ss){

    for(int i=1;i<=n;i++){
        dis[i]=-1;
        vis[i]=0;
        s[i]=0;
    }

    dis[ss]=0;
    vis[ss]=1;
    s[0]=ss;
    q.push({ss,dis[ss]});

    while(!q.empty()){
        int u=q.front().first,ds=q.front().second;
        q.pop();
        for(int i=s[ds]+1;i<=n&&x[i]-x[u]<=d;i++){
            if(dis[i]==-1){
                dis[i]=dis[u]+1;
                q.push({i,dis[i]});
                if(!s[dis[i]]) s[dis[i]]=i;
            }
            if(dis[i]==dis[u]+1){
                vis[i]+=vis[u];
            }
        }
    }
    for(int i=ss+1;i<=n;i++) if(vis[i]==2) ans++;
}

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c,T;
    cin>>c>>T;

    while(T--){
        cin>>n>>d;

        for(int i=1;i<=n;i++){
            cin>>x[i];
        }

        if(c==11||c==12||c==0){
            int pos=upper_bound(x+1,x+1+n,x[1]+d)-x-1;
            if(pos==2){
                cout<<"0\n";
            }
            else{
                cout<<max(0,n-2*(pos-1)+1)<<'\n';
            }
            continue;
        }

        ans=0;

        for(int i=1;i<n;i++){
            bfs(i);
        }

        cout<<ans<<'\n';
    }

    return 0;
}
