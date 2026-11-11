#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
const int maxn=2e6+5,inf=0x3f3f3f3f;
typedef pair<int,int> pr;
int dep[maxn],f[maxn],hson[maxn],md[maxn],ap[maxn],al[maxn],g[maxn],h[maxn],cur,len,in,ik;
vector<int> T[maxn];
inline void getdep(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int v:T[x])if(v!=fa)getdep(v,x);
}
inline void getchain(int x,int fa){
    dep[x]=md[x]=dep[fa]+1;
    for(int v:T[x])if(v!=fa){
        getchain(v,x);
        if(md[v]>md[hson[x]]){
            hson[x]=v;
            md[x]=md[v];
        }
    }
}
inline void init1(int x,int fa){
    dep[x]=md[x]=dep[fa]+1;
    for(int v:T[x])if(v!=fa){
        init1(v,x);
        md[x]=max(md[x],md[v]);
    }
}
inline void init2(int x,int fa){//
    int sz=T[x].size(),pre=f[x];
    if(dep[x]>cur)pre=max(pre,0);
    rep(i,0,sz-1){
        int v=T[x][i];
        if(v==fa)continue;
        f[v]=pre+1;
        if(md[v]>cur)pre=max(pre,md[v]-dep[v]+1);
    }
    pre=f[x];
    if(dep[x]>cur)pre=max(pre,0);
    per(i,sz-1,0){
        int v=T[x][i];
        if(v==fa)continue;
        f[v]=max(f[v],pre+1);
        if(md[v]>cur)pre=max(pre,md[v]-dep[v]+1);
    }
    for(int v:T[x])if(v!=fa)init2(v,x);
}
inline pr cal(int x,int fa){
    pr res=make_pair(0,inf);
    for(int v:T[x])if(v!=fa){
        pr p=cal(v,x);
        res.first+=p.first;
        res.second=min(res.second,p.second);
    }
    if(md[x]-dep[x]>=cur)res.first++;
    if(f[x]<=cur)res.second=min(res.second,res.first);
    return res;
}
inline bool check(int x){
    cur=x;
    int sum=0,mx=0;
    rep(i,x+1,len-x){
        sum++;
        int u=ap[i];
        al[u]=0;
        if(i>x+1&&i<len-x){
            for(int v:T[u])if(v!=ap[i+1]&&v!=ap[i-1]){
                f[v]=-in;
                init2(v,u);
                pr p=cal(v,u);
                // cout<<v<<':'<<p.first<<' '<<p.second<<endl;
                al[u]+=p.first;
                sum+=p.first;
                mx=max(mx,p.first-max(p.second,1));
            }
        }
    }
    // cout<<x<<' '<<sum<<' '<<mx<<endl;
    if(sum-mx<=ik)return true;
    rep(i,1,cur+1)g[i]=1;
    int p=cur+1;
    rep(i,cur+2,len){
        g[i]=g[i-1];
        while(p<i&&md[ap[i]]+i-p>cur){
            p++;
            g[i]+=al[ap[p]]+1;
        }
    }

    per(i,len,len-cur)h[i]=1;
    p=len-cur;
    per(i,len-cur-1,1){
        h[i]=h[i+1];
        while(p>i&&md[ap[i]]+p-i>cur){
            p--;
            h[i]+=al[ap[p]]+1;
        }
    }
    // cout<<cur<<endl;
    rep(i,1,len-1){
        // cout<<i<<':'<<g[i]<<' '<<h[i+1]<<endl;
        if(g[i]+h[i+1]<=ik)return true;
    }
    return false;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int ic,it;
    cin>>ic>>it;
    while(it--){
        scanf("%d %d",&in,&ik);
        rep(i,1,in){
            hson[i]=0;
            T[i].clear();
        }
        rep(i,1,in-1){
            int iu,iv;
            scanf("%d %d",&iu,&iv);
            T[iu].push_back(iv);
            T[iv].push_back(iu);
        }
        if(in==ik){
            printf("0\n");
            continue;
        }
        getdep(1,0);
        int rt=0;
        rep(i,1,in)if(dep[i]>dep[rt])rt=i;
        getchain(rt,0);
        len=0;
        int tmp=rt;
        while(tmp){
            ap[++len]=tmp;
            tmp=hson[tmp];
        }
        ap[len+1]=0;
        rep(i,1,len){
            int u=ap[i];
            md[u]=dep[u]=0;
            for(int v:T[u])if(v!=ap[i-1]&&v!=ap[i+1]){
                init1(v,u);
                md[u]=max(md[u],md[v]);
            }
            // cout<<u<<' '<<md[u]<<endl;
        }
        int l=1,r=len/2,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}