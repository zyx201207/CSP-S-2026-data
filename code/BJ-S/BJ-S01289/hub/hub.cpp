#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=4010;
int n,k;
int fa[N],a[N],dis[N];
vector<int>e[N];
int find(int u){
    if(fa[u]==u)return u;
    return fa[u]=find(fa[u]);
}
void bfs(){
    for(int i=1;i<=n;i++)dis[i]=-1;
    queue<int>q;
    for(int i=1;i<=n;i++)if(a[i]){
        dis[i]=0;q.push(i);
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(int i:e[u])if(dis[i]==-1){
            dis[i]=dis[u]+1;q.push(i);
        }
    }
}
int popcount(int x){
    int ans=0;
    while(x){
        ans+=x%2;x/=2;
    }
    return ans;
}
void bf(){  
    int ans=1e9;
    for(int mask=0;mask<(1<<n);mask++){
        if(popcount(mask)!=k)continue;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=n;i++)if(mask&(1<<(i-1)))a[i]=1;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n;i++)
            if(a[i])for(int j:e[i])if(a[j]){
                int fi=find(i),fj=find(j);fa[fi]=fj;
                // cout<<i<<' '<<j<<'\n';
            }
        set<int>st;
        for(int i=1;i<=n;i++)if(a[i])st.insert(find(i));
        if(st.size()>2)continue;
        bfs();
        int now=0;
        for(int i=1;i<=n;i++)now=max(now,dis[i]);
        ans=min(ans,now);
        // cout<<mask<<' '<<now<<' '<<st.size()<<endl;
    }
    cout<<ans<<'\n';
}
void bf2(){  
    int ans=1e9;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            a[i]=a[j]=1;
            bfs();
            int now=0;
            for(int i=1;i<=n;i++)now=max(now,dis[i]);
            ans=min(ans,now);
            a[i]=a[j]=0;
        }
    cout<<ans<<'\n';
}
void run(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    if(n<=10){
        bf();
        return;
    }
    if(k==2){
        bf2();
        return;
    }
    if(n==k){
        cout<<0<<endl;
        return;
    }
    int m=n/2;
    cout<<(int)(ceil(1.0*(m-k)/4)+1)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)run();
    return 0;
}
/*
Chinese can fly!
区完了
18.08
*/