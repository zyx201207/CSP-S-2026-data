#include<bits/stdc++.h>
#define space putchar(' ');
#define endl putchar('\n');
#define debug puts("------------")
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read();
inline void write(int x);
const int N=1E6+5E5+5,M=5E5+5;
struct Node{
    int nxt,to,val;
}e[N<<1];
int cnte,head[N];
inline void add(int u,int v,int w){
    e[++cnte].to=v;
    e[cnte].val=w;
    e[cnte].nxt=head[u];
    head[u]=cnte;
}
int c,n,m,d,q;
int cntpoint;
map<string,int> dict;
inline int getid(int u,char car){
    stringstream sin;sin<<u;
    string s;sin>>s;
    string name=s+car;
    if(dict.count(name)==0) dict[name]=++cntpoint;
    return dict[name];
}
inline void solve(int k){
    int pre=0;
    ++cntpoint;
    for(int i=1;i<=k;i++){
        int a=read(),t=read();
        int id=getid(a,'B');

        add(id,cntpoint,t);
        add(cntpoint,id,t);

       // write(id);space;write(cntpoint);endl;


/*
        if(i!=1){
            add(cntpoint,pre,0);
            add(pre,cntpoint,0);

           // write(pre);space;write(cntpoint);endl;
        }
        pre=cntpoint;
        */
    }
}
int dis[N];
inline void djs(int s){
    for(int i=1;i<=cntpoint;i++) dis[i]=INF;
    vector<bool> vis(N,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,s));
    dis[s]=0;
    while(!pq.empty()){
        int u=pq.top().second,dist=pq.top().first;
       // write(u);space;write(dist);endl;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].val;
          //  debug;
          //  write(v);space;write(w);endl;
            if(dist+w<dis[v]){
                dis[v]=dist+w;
                pq.push(make_pair(dis[v],v));
            }

        }
    }
}
struct Qu{
    int st,ed,id;
};
bool cp(const Qu &x,const Qu &y){
    return x.st<y.st;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1,w;i<=m;i++){
        w=read();
        int ida=getid(i,'A'),idb=getid(i,'B');

        add(ida,idb,w);
        add(idb,ida,w);
    }
    for(int i=1,k;i<=n;i++){
        k=read();
        solve(k);
    }
    vector<Qu> query(q+1);
    for(int i=1;i<=q;i++){
        query[i].st=read();query[i].ed=read();query[i].id=i;
        if(query[i].st<query[i].ed) swap(query[i].st,query[i].ed);
    }
    sort(query.begin(),query.end(),cp);
    query[0].st=0;
    vector<int> ans(q+1);
    for(int i=1;i<=q;i++){
        if(query[i].st!=query[i-1].st){
            djs(getid(query[i].st,'A'));

        }
        ans[query[i].id]=dis[getid(query[i].ed,'A')];
    }
    for(int i=1;i<=q;i++){
        write(ans[i]);endl;
    }
    return 0;
}
inline int read(){
    int sgn=0,ret=0,ch=getchar();
    while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return sgn?-ret:ret;
}
inline void W(int x){
    if(x>9) W(x/10);
    putchar(x%10+'0');
    return;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    W(x);
    return;
}

//Oct31==Dec25?
