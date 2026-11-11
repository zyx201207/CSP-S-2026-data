#include<bits/stdc++.h>
#define ll long long

using namespace std;

int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}

struct ed{int v,w;};
vector<ed> ling[500505];
int c,n,m,d,q,w[500005],a[500005],t,cnt;

int vis1[10][500505],vis2[505][30005];
ll dis1[10][500505],dis2[505][30005];
void dijkstra1(int id,int u){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dis1[id][u]=0,pq.push({0,u});
    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(vis1[id][x]) continue;
        vis1[id][x]=1;
        for(ed i:ling[x]){
            if(dis1[id][i.v]>dis1[id][x]+i.w){
                dis1[id][i.v]=dis1[id][x]+i.w;
                pq.push({dis1[id][i.v],i.v});
            }
        }
    }
}
void dijkstra2(int id,int u){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dis2[id][u]=0,pq.push({0,u});
    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(vis2[id][x]) continue;
        vis2[id][x]=1;
        for(ed i:ling[x]){
            if(dis2[id][i.v]>dis2[id][x]+i.w){
                dis2[id][i.v]=dis2[id][x]+i.w;
                pq.push({dis2[id][i.v],i.v});
            }
        }
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    cnt=m;
    for(int i = 1;i<=m;i++) w[i]=read();
    for(int j = 1;j<=n;j++){
        int k=read(),nw=++cnt;
        for(int i = 1;i<=k;i++){
            a[i]=read(),t=read();
            ling[a[i]].push_back({nw,t});
            ling[nw].push_back({a[i],t});
        }
    }
    if(c==20||c==21){
        memset(vis1,0,sizeof vis1);
        memset(dis1,0x3f,sizeof dis1);
        for(int i = 1;i<=n;i++) dijkstra1(i,m+i);
        while(q--){
            int x=read(),y=read();
            if(x>y) swap(x,y);
            ll ans=LLONG_MAX;
            for(ed i:ling[x]) ans=min(ans,1LL*i.w+dis1[i.v-m][y]);
            ans+=w[x]+w[y];
            printf("%lld\n",ans);  
        }
    }else if(1<=c&&c<=15){
        memset(vis2,0,sizeof vis2);
        memset(dis2,0x3f,sizeof dis2);
        for(int i = 1;i<=n;i++) dijkstra2(i,m+i);
        while(q--){
            int x=read(),y=read();
            if(x>y) swap(x,y);
            ll ans=LLONG_MAX;
            for(ed i:ling[x]) ans=min(ans,1LL*i.w+dis2[i.v-m][y]);
            ans+=w[x]+w[y];
            printf("%lld\n",ans);  
        }
    }

    return 0;
}