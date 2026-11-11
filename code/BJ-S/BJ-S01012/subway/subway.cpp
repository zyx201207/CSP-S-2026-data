#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int N=505,M=5e5+10,D=25;
int w[M],dis[M*D],l[M],a[M],t[M];
vector<pii>g[M*D];
vector<pii>ng[N],ng1[N];
vector<int>r[M];

int dij(int s,int t){
    priority_queue<pii>q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().se;
        q.pop();
        for(pii i:g[u]){
            int v=i.se;
            if(dis[v]>dis[u]+i.fi){
                dis[v]=dis[u]+i.fi;
                q.push({dis[v],v});
            }
        }
    }
    return dis[t];
}

int dij2(int s,int t){
    priority_queue<pii>q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().se;
        q.pop();
        for(pii i:ng1[u]){
            int v=i.se;
            if(dis[v]>dis[u]+i.fi){
                dis[v]=dis[u]+i.fi;
                q.push({dis[v],v});
            }
        }
    }
    return dis[t];
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    int T=-1,flag=0;
    fr(i,1,m)cin>>w[i]; 
    fr(i,1,n){
        int k;cin>>k;
        fr(j,1,k){
            cin>>a[j]>>t[j];
            if(t[j]!=T)flag++,T=t[j];
            int u=a[j]+m*l[a[j]],st=a[j]+m*(d+1);
            g[u].pb({t[j],st}),g[st].pb({t[j],u});
            r[a[j]].pb(i);
        }
        fr(j,2,k){
            int u=a[j]+m*l[a[j]],v=a[j-1]+m*l[a[j-1]];
            if(j!=1)g[u].pb({0,v}),g[v].pb({0,u});
        }
        fr(j,1,k)l[a[j]]++;
    }
    
    if(flag==1){
        
        fr(i,1,m){
            int sz=r[i].size();
            fr(j,0,sz-1)fr(k,j+1,sz-1)ng[r[i][j]].pb({2*T,r[i][k]}),ng[r[i][k]].pb({2*T,r[i][j]});
        }
        
        while(q--){
            fr(i,1,N)dis[i]=1e18;
            int x,y;cin>>x>>y;
            fr(i,1,N)ng1[i]=ng[i];
            for(int i:r[x])ng1[502].pb({T,i});
            for(int i:r[y])ng1[i].pb({T,503});
            cout<<w[x]+dij2(502,503)+w[y]<<'\n';
        }
        
        return 0;
    }
    
    for(int i=1;i<=q;i++){
        fr(i,1,2*m*d)dis[i]=1e18;
        int x,y;cin>>x>>y;
        cout<<w[x]+dij(x+(d+1)*m,y+(d+1)*m)+w[y]<<'\n';
    }
    return 0;
}