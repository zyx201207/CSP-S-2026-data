#include<cstdio>
using namespace std;
#define N 1000006
int C,t;
int n,k;
struct edge{
    int v,ne;
}e[N];
int h[N],ecnt;//
void add(int u,int v){
    e[++ecnt]=edge{v,h[u]};
    h[u]=ecnt;
}
int dee,len;
int dep[N],son[N],maxdep[N];
int dp[N];
int li[N];
void dfs1(int x,int f){
    dep[x]=dep[f]+1;
    for(int c=h[x];c!=0;c=e[c].ne){
        if(e[c].v==f) continue;
        dfs1(e[c].v,x);
    }
}
void dfs2(int x,int f){
    dep[x]=dep[f]+1;
    maxdep[x]=dep[x];
    for(int c=h[x];c!=0;c=e[c].ne){
        if(e[c].v==f) continue;
        dfs2(e[c].v,x);
        if(maxdep[e[c].v]>maxdep[x]) maxdep[x]=maxdep[e[c].v],son[x]=e[c].v;
    }
}
bool need[N];
int dfs3(int l,int x,int f){
    dep[x]=dep[f]+1;
    int ans=0;
    maxdep[x]=dep[x];
    for(int c=h[x];c!=0;c=e[c].ne){
        if(e[c].v==f) continue;
        ans+=dfs3(l,e[c].v,x);
        if(maxdep[e[c].v]>maxdep[x]) maxdep[x]=maxdep[e[c].v];
    }
    if(maxdep[x]-dep[x]>=l) return ans+1;
    else return ans;
}
bool check(int x){
    int sum=0;
    if(x*2>=len) return 1;
    for(int c=0;c<len;c++) need[c]=0;
    need[x]=1,need[len-x-1]=1;
    int last=x;
    for(int c=x;c<len-x;c++){
        if(need[c]) last=c;
        if(c-last-1>=x) need[last+1]=1;
        for(int i=h[li[c]];i!=0;i=e[i].ne){
            if(e[i].v==li[c-1]||e[i].v==li[c+1]) continue;
            sum+=dfs3(x,e[i].v,li[c]);
            if(maxdep[e[i].v]<x) need[x-maxdep[e[i].v]-1+c]=1,need[-(x-maxdep[e[i].v]-1)+c]=1;
            else need[c]=1;
            last=c;
        }
    }
    last=x;
    int lon=0;
    for(int c=x;c<len-x;c++){
        if(need[c]){
            if(c-last-1>lon) lon=c-last-1;
            last=c;
        }
    }
    sum+=len-x*2-lon;
    // printf("check:%d %d %d\n",x,sum,lon);
    return sum<=k;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&t);
    while(t--){
        ecnt=0;
        scanf("%d%d",&n,&k);
        for(int c=0;c<=n;c++) h[c]=0,son[c]=0,dep[c]=0,maxdep[c]=0;
        for(int c=1,u,v;c<n;c++){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        dfs1(1,0);
        dee=0;
        for(int c=1;c<=n;c++) if(dep[c]>dep[dee]) dee=c;
        dfs2(dee,0);
        len=0;
        for(int c=dee;c!=0;c=son[c]) li[len++]=c;
        // printf("len %d\n",len);
        int l=0,r=n,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
}