#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    #define clog cerr
    constexpr int maxn=2e6+3,inf=0x3f3f3f3f;vector<int>e[maxn],buf[maxn],suf[maxn];
    int maxdep[maxn],route[maxn],tot,f[maxn],vec[maxn],arr[maxn];bool vis[maxn];
    inline void calc_depth(int u,int last){maxdep[u]=0;
        for(int v:e[u])if(v!=last)calc_depth(v,u),maxdep[u]=max(maxdep[u],maxdep[v]);
        ++maxdep[u];}
    inline void summarize(int u,int last,int lim){f[u]=maxdep[u]>lim;
        for(int v:e[u])if(v!=last)summarize(v,u,lim),f[u]+=f[v];}
    inline int calculate(int u,int last,int lim,int dep,int maxx){
        if(dep+maxx>lim)return inf;int res=max(1,f[u]),siz=e[u].size();
        if(e[u].size()==1)return res;
        for(int i=0;i<siz;++i){int v=e[u][i];if(v==last){buf[u][i]=-inf;continue;}
            buf[u][i]=dep+maxdep[v]<=lim?-inf:maxdep[v]-dep;}
        for(int i=siz-1,cur=-inf;i>=0;--i)suf[u][i]=cur,cur=max(cur,buf[u][i]);
        for(int i=0;i<siz;++i){int v=e[u][i];if(v==last)continue;
            res=min(res,calculate(v,u,lim,dep+1,max(maxx,suf[u][i])))
            ,maxx=max(maxx,buf[u][i]);}return res;}
    inline bool check(int lim,int m){if(lim>=tot>>1)return true;
        int mid=route[tot+1>>1];calc_depth(mid,0),summarize(mid,0,lim);
        if(f[mid]<=m)return true;for(int i=1;i<=tot;++i){
            int u=route[i];for(int v:e[u])if(!vis[v]&&f[v]&&
                f[mid]-f[v]+calculate(v,u,lim,1,-1)<=m)return true;}
        for(int i=1;i<=lim+1;++i)vec[i]=1;int root=route[lim+1];
        calc_depth(root,0),summarize(root,0,lim);int ite=lim+1,sum=1;
        for(int v:e[route[ite]])if(!vis[v])sum+=f[v];
        for(int i=lim+2;i<=tot;++i){int dist=0;
            for(int v:e[route[i]])if(!vis[v])dist=max(dist,maxdep[v]);
            while(ite<i&&i-ite+dist>lim){++ite,++sum;
                for(int v:e[route[ite]])if(!vis[v])sum+=f[v];}
            vec[i]=sum;}
        for(int i=tot;i>=tot-lim;--i)arr[i]=1;
        calc_depth(root,0),summarize(root,0,lim),ite=tot-lim,sum=1;
        for(int v:e[route[ite]])if(!vis[v])sum+=f[v];
        for(int i=tot-lim-1;i;--i){int dist=0;
            for(int v:e[route[i]])if(!vis[v])dist=max(dist,maxdep[v]);
            while(ite>i&&ite-i+dist>lim){--ite,++sum;
                for(int v:e[route[ite]])if(!vis[v])sum+=f[v];}
            arr[i]=sum;}
        //clog<<"vec:";for(int i=1;i<=tot;++i)clog<<vec[i]<<' ';clog<<'\n';
        //clog<<"arr:";for(int i=1;i<=tot;++i)clog<<arr[i]<<' ';clog<<'\n';
        for(int i=1;i<tot;++i)if(vec[i]+arr[i+1]<=m)return true;
        return false;}
    inline int Main(){int testcase,test;cin>>testcase>>test;while(test--){
        int n,m;cin>>n>>m;
        for(int i=1,u,v;i<n;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
        for(int i=1;i<=n;++i)buf[i].resize(e[i].size()),suf[i].resize(e[i].size());
        calc_depth(1,0);int x=1;while(maxdep[x]>1)
            for(int v:e[x])if(maxdep[v]==maxdep[x]-1){x=v;break;}
        calc_depth(x,0),tot=1,route[1]=x;int y=x;while(maxdep[y]>1)
            for(int v:e[y])if(maxdep[v]==maxdep[y]-1){route[++tot]=y=v;break;}
        /*clog<<"route:\n";
        for(int i=1;i<=tot;++i)clog<<route[i]<<' ';clog<<'\n';*/
        for(int i=1;i<=tot;++i)vis[route[i]]=true;
        int l=0,r=n;while(l!=r){int mid=l+r>>1;//clog<<"check:"<<mid<<'\n';
            if(check(mid,m))r=mid/*,clog<<"success\n"*/;else l=mid+1/*,clog<<"fail\n"*/;}
        for(int i=1;i<=n;++i)e[i].clear(),buf[i].clear(),e[i].clear();
        memset(vis+1,false,n),cout<<l<<'\n';
        }return 0;
    }
}
int main(){freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    SOLUTION::Main();return 0;
}