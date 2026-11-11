#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f;
int c,t,n,d;
int x[N];
int to[N];

inline bool judge(int x,int y){
    int mdis=inf,cnt=0;
    int dis[505];
    memset(dis,inf,sizeof dis);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,x));
    while(!q.empty()){
        int diss=q.top().first;
        int u=q.top().second;
        q.pop();
        if(u==y){
            if(diss>mdis){
                continue;
            }else if(diss<mdis){
                mdis=diss;
                cnt=1;
            }else{
                cnt++;
            }
            continue;
        }
        for(int v=u+1;v<=to[u]&&v<=n;v++){
            if(dis[v]>=diss+1){
                dis[v]=diss+1;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    return (cnt==2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            to[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
        }
        if(n<=300){
            int ans=0;
            for(int u=1;u<=n;u++){
                for(int v=u+1;v<=n;v++){
                    if(judge(u,v)){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}
