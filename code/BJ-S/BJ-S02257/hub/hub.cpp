#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int N=2e6+5;
int n,k,deg[N],p[N],cdeg[N],f[N],h[N],bel[N],dep[N];
int q[N],path[N],dq1[N],dq2[N];
vector<int>edge[N];
int init(){int l=0,r=0,mx=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(deg[i]<=1)p[i]=0,q[r++]=i;
    }while(l<r){int u=q[l++];
        for(auto v:edge[u]){
            if(p[v]!=-1)continue;
            if(--deg[v]==1)p[v]=p[u]+1,q[r++]=v;
        }
    }for(int i=1;i<=n;i++){
        if(p[i]>mx)mx=p[i],cnt=1;
        else if(p[i]==mx)cnt++;
    }return mx+(cnt==2);
}bool check(int R){
    if(!R)return k==n;
    int l=0,r=0,sz=0;
    for(int i=1;i<=n;i++){
        f[i]=(p[i]>=R);
        cdeg[i]=h[i]=dep[i]=0;
        bel[i]=f[i]?i:0;
        if(f[i])q[r++]=i,sz++;
    }if(sz<=k)return 1;int tmp=sz-k;
    for(int i=1;i<=n;i++){
        if(!f[i])continue;
        for(auto v:edge[i])cdeg[i]+=f[v];
    }while(l<r){int u=q[l++];
        for(auto v:edge[u]){
            if(bel[v])continue;
            bel[v]=bel[u],dep[v]=dep[u]+1;
            h[bel[v]]=max(h[bel[v]],dep[v]),q[r++]=v;
        }
    }for(int st=1;st<=n;st++){
        if(!f[st]||cdeg[st]==2)continue;
        for(auto v:edge[st]){
            if(!f[v])continue;
            int m=1,pre=st,cur=v;path[0]=st;
            while(1){path[m++]=cur;int nxt=-1;
                if(cdeg[cur]!=2)break;
                for(auto x:edge[cur]){
                    if(f[x]&&x!=pre){nxt=x;break;}
                }pre=cur;cur=nxt;
            }if(st>=cur||m-2<tmp)continue;
            int h1=0,t1=0,h2=0,t2=0,add1=-1,add2=-1,b=1;
            auto chk=[&](int a,int b)->bool {int mid=a+b>>1;
                while(add1<mid){int x=++add1,val=h[path[x]]+x;
                    while(h1<t1&&h[path[dq1[t1-1]]]+dq1[t1-1]<=val)t1--;dq1[t1++]=x;
                }while(h1<t1&&dq1[h1]<=a)h1++;
                while(add2<b-1){int x=++add2,val=h[path[x]]-x;
                    while(h2<t2&&h[path[dq2[t2-1]]]-dq2[t2-1]<=val)t2--;dq2[t2++]=x;
                }while(h2<t2&&dq2[h2]<=mid)h2++;
                bool f1=(h1==t1||h[path[dq1[h1]]]+dq1[h1]-a<=R);
                bool f2=(h2==t2||h[path[dq2[h2]]]-dq2[h2]+b<=R);
                return f1&&f2;
            };for(int a=0;a<m-1;a++){b=max(b,a+1);
                while(b+1<m&&chk(a,b+1))b++;
                if(b-a-1>=tmp)return 1;
            }
        }
    }return 0;
}void solve(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){edge[i].clear();deg[i]=0,p[i]=-1;}
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        edge[u].push_back(v);
        edge[v].push_back(u);
        deg[u]++;deg[v]++;
    }int l=0,r=init();
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }cout<<l<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read();int t=read();
    while(t--)solve();
    return 0;
}

//g++ -std=c++14 -O2 D.cpp -o D