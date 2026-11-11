#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=1e7+10;
int c,n,m,l,q;
int w[M];
int a[M];
int t[M];
long long d[M];
int pre[M];
bool vis[M];
int k,id=0;
int x,y;

struct node {
    int from,to,len,next;
} s[N];

void add(int u,int v,int len){
    ++id;
    s[id].from = u;
    s[id].to = v;
    s[id].len = len;
    s[id].next = pre[u];
    pre[u]=id;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>l>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }

    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a[j];
            cin>>t[j];
            for(int s=1;s<j;++s){
                add(a[s],a[j],t[s]+t[j]);
                add(a[j],a[s],t[s]+t[j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        cin>>x>>y;
        int ans = w[x]+w[y];
        memset(d,0x3f,sizeof(d));
        memset(vis,false,sizeof(vis));
        d[x]=0;
        for(int j=1;j<=n;++j){
            int mi=-1;
            for(int k=1;k<=n;++k){
                if(!vis[k] &&(mi==-1||d[k]<d[mi])) mi=k;
            }
            vis[mi]=true;
            for(int j=pre[mi];j!=0;j=s[j].next){
                int to = s[j].to;
                if(d[mi]+s[j].len < d[to])
                    d[to] = d[mi]+s[j].len;
            }
        }
        cout<<ans+d[y]<<endl;
    }
    return 0;
}
