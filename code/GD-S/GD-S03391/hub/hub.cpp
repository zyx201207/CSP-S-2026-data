#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n,k;
vector<int> g[1100000];
int tr[1100000],top;
namespace GetChain {
    int Fa[1100000];
    pair<int,int> dfs(int x,int fa,int dep) {
        pair<int,int> ans={dep,x};
        Fa[x]=fa;
        for(int i:g[x]) {
            if(i==fa) continue;
            ans=max(ans,dfs(i,x,dep+1));
        }
        return ans;
    }
    void FindChain(int x) {
        tr[++top]=x;
        if(Fa[x]) FindChain(Fa[x]);
    }
}


int vis[1100000];
int val[1100000];
int dfs(int x,int T,int rt) {
    vis[x]=1;
    int high=0;
    for(int i:g[x]) {
        if(vis[i]==1) continue;
        high=max(high,dfs(i,T,rt));
    }
    high++;
    // printf("$$  %d %d\n",high,T);
    if(high>T) val[rt]++;
    return high;
}
int high[1100000];

pair<int,int> st[1100000];
int N;

int Tmp1[1100000];
int Tmp2[1100000];
int MinCost[1100000];

bool check(int T) {
    // memset(Tmp1,0,sizeof(Tmp1));
    // memset(Tmp2,0,sizeof(Tmp2));
    // memset(MinCost,0,sizeof(MinCost));
    if(T+1>top-T) return 1;
    int Ans=0;
    for(int i=1;i<=n;i++) vis[i]=val[i]=0,Tmp1[i]=0;
    for(int i=T+1;i<=top-T;i++) vis[tr[i]]=1;
    int lst=-1;
    N=0;
    for(int i=T+1;i<=top-T;i++) {
        int u=tr[i];
        high[u]=dfs(u,T,u);
        Ans+=val[u];
        if(val[u]) {
            if(lst==-1) lst=i;
            else {
                st[++N]={lst,i};
                lst=i;
            }
            high[u]=0;
        }
        // printf("%d : %d %d\n",i,high[u],val[u]);
    }
    if(T+1==top-T) {
        return val[tr[T+1]]<=k;
    }
    for(int i=1;i<=N;i++) {
        Tmp1[st[i].first]=0;
        for(int j=st[i].first+1;j<=st[i].second;j++) {
            int u=tr[j];
            //high[u]+j-st[i].first-T<=dj
            Tmp1[j]=max(high[u]+j-st[i].first-T-1,Tmp1[j-1]);
        }
        Tmp2[st[i].second]=0;
        for(int j=st[i].second;j>=st[i].first;j--) {
            int u=tr[j];
            //high[u]+st[i].second-j-T<=dj
            Tmp2[j]=max(high[u]+st[i].second-j-T-1,Tmp2[j+1]);
        }
        MinCost[i]=0x3f3f3f3f;
        for(int j=st[i].second;j>=st[i].first+1;j--) {
            int u=tr[j];
            // printf("%d %d\n",Tmp1[j-1],Tmp2[j]);
            MinCost[i]=min(MinCost[i],Tmp1[j-1]+Tmp2[j]);
        }
    }
    int Ssum=0,Psum=0;
    for(int i=1;i<=N;i++) Ssum+=st[i].second-st[i].first-1;
    int Min=0x3f3f3f3f;
    for(int i=1;i<=N;i++) {
        Ssum-=st[i].second-st[i].first-1;
        Min=min(Min,Ssum+Psum+MinCost[i]);
        Psum+=st[i].second-st[i].first-1;
    }
    Ans+=Min;
    return Ans<=k;
}

int solve() {
    scanf("%d%d",&n,&k);
    top=0;
    for(int i=1;i<=n;i++) g[i].clear(),tr[i]=0,val[i]=vis[i]=0,high[i]=0,Tmp1[i]=Tmp2[i]=MinCost[i]=0;
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    top=0;
    pair<int,int> tmp=GetChain::dfs(1,0,1);
    tmp=GetChain::dfs(tmp.second,0,1);
    GetChain::FindChain(tmp.second);

    // printf("%d\n",check(0));
    int l=0,r=n;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    for(int i=1;i<=n;i++) g[i].clear();
    return 0;
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int Id,T;
    scanf("%d%d",&Id,&T);
    while(T--) {
        solve();
    }
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


0 1
5 2
1 2
2 3
3 4
4 5
*/