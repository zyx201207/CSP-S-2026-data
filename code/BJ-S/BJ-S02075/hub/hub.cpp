#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000000+10;
vector<int>vc[N];
int n,m,testcase,fa[N],fa2[N],col[N],sz[3][N],totsz[3],dep[N],dis[N];
using pii=pair<int,int>;
#define fi first
#define sc second
pii findF(int u,int f){
    pii res=pii(u,0);fa[u]=f;
    for(auto v:vc[u])if(v!=f){
        pii tmp=findF(v,u);
        tmp.sc++;
        if(res.sc<tmp.sc)res=tmp;
    }return res;
}
pii findF2(int u,int f){
    pii res=pii(u,0);fa2[u]=f;
    for(auto v:vc[u])if(col[u]==col[v]&&v!=f){
        pii tmp=findF2(v,u);
        tmp.sc++;
        if(res.sc<tmp.sc)res=tmp;
    }return res;
}


inline void paint(int u,int f,int c){
    totsz[col[u]=c]++;for(auto v:vc[u])if(v!=f)paint(v,u,c);
}
inline int findH(int u,int f){
    dep[u]=dep[f]+1,sz[col[u]][u]=1;int res=0;
    for(auto v:vc[u])if(col[v]==col[u]&&v!=f){
        int tmp=findH(v,u);
        if(!res)res=tmp;
        else if(tmp&&dep[tmp]>dep[res])tmp=res;
        sz[col[u]][u]+=sz[col[u]][v];
    }
    //cout<<"\tfindH: "<<u<<','<<col[u]<<"; "<<sz[col[u]][u]<<endl;
    if(!res&&sz[col[u]][u]*2>=totsz[col[u]])res=u;
    //cout<<"\t\t"<<res<<"; "<<totsz[col[u]]<<endl;
    return res;
}

inline int check(int u,int f,int w){
    //cout<<"!!!check: "<<u<<','<<w<<endl;
    int res=0;dis[u]=w;
    for(auto v:vc[u])if(col[u]==col[v]&&v!=f){
        res+=check(v,u,w);
        dis[u]=min(dis[u],dis[v]-1);
    }
    dis[u]=max(dis[u],0);
    if(dis[u]==0||f==0)res++;
    //cout<<"\tend-check "<<u<<": "<<res<<"; "<<dis[u]<<endl;
    //if(f==0)cout<<"\n";
    return res;
}

inline int solve(int u1,int v1){
    //cout<<"!!!solve "<<u1<<','<<v1<<endl;
    totsz[1]=totsz[2]=0,paint(u1,v1,1),paint(v1,u1,2);
    ///r1=findH(u1,0),r2=findH(v1,0);
    int l1=findF2(u1,0).fi,l2=findF2(v1,0).fi;
    pii e1=findF2(l1,0),e2=findF2(l2,0);
    int p1=e1.fi,p2=e2.fi,lf1=e1.sc>>1,lf2=e2.sc>>1;
    while(lf1)p1=fa2[p1],lf1--;while(lf2)p2=fa2[p2],lf2--;
    int res=n;
    for(int i=0,r1,r2;i<4;i++){
        if(i&1)r1=fa2[p1];else r1=p1;
        if(i&2)r2=fa2[p2];else r2=p2;
        if(!r1||!r2)continue;
        //cout<<"\t"<<r1<<","<<r2<<endl;
        int l=0,r=n/2+1,mid;
        while(l<r){
            mid=(r+l)>>1;
            int w1=check(r1,0,mid),w2=check(r2,0,mid);
            //cout<<"\t\t"<<mid<<":  "<<w1<<"; "<<w2<<endl;
            if(w1+w2<=m)r=mid;
            else l=mid+1;
        }
        res=min(res,l);
    }
    //cout<<"end-solve "<<u1<<','<<v1<<": "<<res<<endl;
    return res;
}

void test(){
    cin>>n>>m;for(int i=1;i<=n;i++)vc[i].clear();
    for(int i=2,u,v;i<=n;i++)cin>>u>>v,vc[u].pb(v),vc[v].pb(u);
    int u=findF(1,0).fi;pii ed=findF(u,0);
    //cout<<"!!!"<<u<<"; "<<ed.fi<<"; "<<ed.sc<<endl;
    if(n<=300000){
        int p=ed.fi,lft=max(0,(ed.sc>>1)-10);while(lft)p=fa[p],lft--;
        int ans=n;
        for(int i=0;i<20&&p!=u;i++,p=fa[p]){
            ans=min(ans,solve(fa[p],p));
        }cout<<ans<<'\n';
    }else{
        int p=ed.fi,lft=max(0,(ed.sc>>1)-5);while(lft)p=fa[p],lft--;
        int ans=n;
        for(int i=0;i<10&&p!=u;i++,p=fa[p]){
            ans=min(ans,solve(fa[p],p));
        }cout<<ans<<'\n';
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;cin>>testcase>>t;while(t--)test();
    return 0;
}

