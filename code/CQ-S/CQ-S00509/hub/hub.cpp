/*
16:10
我两个半小时还不能过这个题？
*/
#include<bits/stdc++.h>
// #define int long long
#define ll long long
#define maxm 1000005
#define maxn 1005
#define msk cerr
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
namespace Sasuke{
    int cas,T,n,m,ans;
    int a[maxm];
    vector<int>e[maxm];
    int de[maxm],f[maxm];
    void init(){
        static int in[maxm];
        queue<int>q;
        for(int i=1;i<=n;i++){
            in[i]=f[i]=0;
            if(e[i].size()==1)q.push(i);
        }
        while(q.size()){
            int x=q.front();q.pop();in[x]=1;
            for(int y:e[x]){
                if(in[y])continue;
                --de[y];f[y]=max(f[y],f[x]+1);
                if(de[y]==1)q.push(y);
            }
        }
        for(int i=1;i<=n;i++)de[i]=0;
        // msk<<"f:";for(int i=1;i<=n;i++)msk<<f[i]<<" ";msk<<"\n";
    }
    struct edge{int fr,to,nxt;}E[maxm<<1];
    int h[maxm],star;
    void ade(int x,int y){E[++star]={x,y,h[x]};h[x]=star;}
    int N,Id[maxm],g[maxm];
    int rt,dep[maxm],vis[maxm];
    void Dfs(int x,int fath){
        dep[x]=dep[fath]+1;
        // msk<<fath<<"->"<<x<<" dep:"<<dep[x]<<"\n";
        if(dep[x]>dep[rt])rt=x;
        for(int i=h[x];i;i=E[i].nxt){
            int y=E[i].to;
            if(y==fath||de[y]!=2)continue;
            Dfs(y,x);
        }
    }
    int s[maxm],L[maxm],R[maxm];
    // vector<int>q[maxm];
    int Mx[maxm];
    bool ck(int mid){
        // msk<<"ck:"<<mid<<"==================\n";
        // static int F[maxm];
        for(int i=1;i<=n;i++)if(f[i]>=mid){
            Id[i]=++N;g[N]=0;//F[N]=f[i];
            for(int x:e[i])if(f[x]<mid)g[N]=max(g[N],f[x]+1);
        }
        for(int i=1;i<=n;i++)for(int x:e[i])
            if(Id[i]&&Id[i]<Id[x]){
                // msk<<"ade:"<<Id[i]<<" "<<Id[x]<<"\n";
                ade(Id[i],Id[x]);ade(Id[x],Id[i]);
                de[Id[i]]++;de[Id[x]]++;
            }
        // msk<<"N:"<<N<<"\n";
        int mx=0;
        for(int i=1;i<=star;i+=2){
            int x=E[i].fr,y=E[i].to;
            // msk<<x<<"->"<<y<<"\n";
            // Sol(x,y,mid);Sol(y,x,mid);
        }
        for(int i=1;i<=N;i++)if(de[i]==2&&!vis[i]){
            rt=0;Dfs(i,0);
            int M=0;
            int x=rt;
            while(1){
                vis[x]=1;int fl=0;s[++M]=x;
                for(int i=h[x];i;i=E[i].nxt){
                    int y=E[i].to;
                    if(de[y]!=2)continue;
                    if(!vis[y]){x=y;fl=1;break;}
                }
                if(!fl)break;
            }
            for(int i=1;i<=M;i++){
                L[i]=max(0,i-(mid-g[s[i]]));
                R[i]=min(M+1,i+(mid-g[s[i]]));
                Mx[R[i]]=max(Mx[R[i]],L[i]+1);
                // msk<<i<<":["<<L[i]<<","<<R[i]<<"]\n";
                // q[R[i]].push_back(i);
            }
            Mx[1]=max(Mx[1],1);
            for(int i=1;i<=M;i++){
                Mx[i]=max(Mx[i],Mx[i-1]);
                mx=max(mx,i-Mx[i]+1);
            }
            // msk<<"s:";for(int i=1;i<=M;i++)msk<<s[i]<<" ";msk<<"\n";
            // msk<<"g:";for(int i=1;i<=M;i++)msk<<g[s[i]]<<" ";msk<<"\n";
            // msk<<"f:";for(int i=1;i<=M;i++)msk<<F[s[i]]<<" ";msk<<"\n";
            // msk<<"mx:"<<mx<<"\n";
            // for(int r=1;r<=M;r++)for(int l=1;l<=r;l++){
            //     int fl=1;
            //     for(int i=l;i<=r;i++)if(L[i]>=l&&R[i]<=r){fl=0;break;}
            //     if(fl)mx=max(mx,r-l+1);
            // }

            for(int i=1;i<=M+1;i++)Mx[i]=0;
        } 
        // msk<<"mx:"<<mx<<"\n";
        int fl=N-mx<=m;
        // msk<<"flag:"<<fl<<"\n";
        //cle
        for(int i=1;i<=n;i++)vis[i]=h[i]=Id[i]=de[i]=0;
        star=N=0;
        return fl;
    }
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin>>cas>>T;
        for(int ii=1;ii<=T;ii++){
            // msk<<ii<<"===============================\n";
            cin>>n>>m;
            // if(ii==2)msk<<n<<" "<<m<<"\n";
            for(int i=1;i<n;i++){
                int x,y;cin>>x>>y;
                // if(ii==2)msk<<x<<" "<<y<<"\n";
                e[x].push_back(y);
                e[y].push_back(x);
                de[x]++;de[y]++;
            }
            init();
            int l=0,r=0,res=n+1;
            for(int i=1;i<=n;i++)r=max(r,f[i]);
            // ck(9);return 0;
            while(l<=r){
                int mid=l+r>>1;
                if(ck(mid))res=mid,r=mid-1;
                else l=mid+1;
            }
            cout<<res<<"\n";
            // if(ii==2)break;
            //  
            for(int i=1;i<=n;i++)de[i]=f[i]=0,e[i].clear();
        }
        return 0;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    // freopen("hub5.in","r",stdin);
    freopen("hub.out","w",stdout);
    freopen("ssk.err","w",stderr);
    Sasuke::main();//while(1);
    msk<<"TIME:"<<clock()/1./CLOCKS_PER_SEC<<"\n";
    return 0;
}
/*
g++ -o hub hub.cpp -std=c++14 -Wall -Wl,--stack=20000000 -O2 & .\hub   
*/