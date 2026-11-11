#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int c,t,n,k,fa[1000005][25],dep[1000005],f[1000005],ans;
bool v[1000005];
vector<int> G[1000005];
void dfsp(int x){for(int u:G[x]) if(u!=fa[x][0]) fa[u][0]=x,dep[u]=dep[x]+1,dfsp(u);}
void init(){for(int j=1;(1<<j)<=n;j++) for(int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
void init(int n){for(int i=1;i<=n;i++) f[i]=i;}
int getfa(int x){return f[x]==x?x:f[x]=getfa(f[x]);}
void merge(int x,int y){f[getfa(x)]=getfa(y);}
void dfs(int x,int sum){
    if(x>n){
        init(n);
        for(int i=1;i<=n;i++) if(v[i] and v[fa[i][0]]) merge(i,fa[i][0]);
        int fa1=0,fa2=0;
        for(int i=1;i<=n;i++) if(v[i]){
            int t=getfa(i);
            if(fa1 and t!=fa1 and fa2 and t!=fa2) return;
            if(!fa1) fa1=t;
            else if(t!=fa1 and !fa2) fa2=t;
        }
        int mx=0;
        for(int i=1;i<=n;i++) if(!v[i]){
            int mn=0x3f3f3f3f;
            for(int j=1;j<=n;j++) if(v[j]) mn=min(mn,dis(i,j));
            mx=max(mx,mn);
        }
        ans=min(ans,mx);
        return;
    }
    if(sum<k) v[x]=true,dfs(x+1,sum+1),v[x]=false;
    dfs(x+1,sum);
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    dep[0]=-1;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            G[u].push_back(v),G[v].push_back(u);
        }
        dfsp(1),init(),ans=0x3f3f3f3f,dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
/*
I'm just an ordinary OIer.
100+100+16+15=231
尽力了，希望不要挂分，拿个1=
---
现在是 18:10
考场通知：第二题样例解释忽略公式变量。
---
游记
Day0 / 10.31 上午
复习了一些算法板子（实际上只有 LCA 用上了），在虚拟机 NOI Linux 上试了试 Arbiter（前几年场上尝试用 Arbiter 都失败了）。
中午看到 , 群里有人说 AK 了 J，但是由于没坐过高铁，以为有 E 座导致 T1 挂分了。
13:40 出发去学校，路上遇到了一些大佬。
Day1 / 10.31 下午
到了考场发现和去年居然坐在同一个机位（？
希望能一雪去年没过 T1 的前耻。
考前配了下 VSCode 和 Arbiter。

开考直接开 T1，也是很快就想到了 O(n) 做法。由于饭堂多处细节写挂，调了快半小时。
而后开始写暴力并对拍，拍到 7000 多组数据的时候发现 WA 了，缩小数据规模拍 10000 组都没出错。
输中量调试发现正解和暴力都忘开 ll 了！

15:30，T1 通过，开 T2。这年头 S T2 都能被我一眼了吗？
T2 用了 Floyd，考前没复习！还好凭借印象写出来了。
16:10 过 T2，不会写 gen 所以没对拍。

然后就拼 T3（暴力+性质A）和 T4（暴力）的部分分。
17:55 开始检查代码，发现 T3 又忘开 ll 了。

场上估分：100+100+16+15=231pts。
*/