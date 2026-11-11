#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pow power
#define ull unsigned ll
template<typename T>void read(T &x){
    x=0; int f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    } 
    while(isdigit(c)) x=10*x+c-'0',c=getchar();
    x*=f;
}
template<typename T>void write(T x){
    if(x<0) putchar('-'),write(-x);
    else if(x<10) putchar(x+'0');
    else write(x/10),putchar(x%10+'0');
}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=1e6+5;
int c,T,n,k,fa[N],dep[N],vis[N],len[N],mx;
vector<int>g[N],sz[N];
vector<int>d;
vector<int>work;
void dfs1(int x){
    work.push_back(x);
    mx=max(mx,dep[x]);
    for(int v:g[x]){
        if(v==fa[x]||vis[v]) continue;
        fa[v]=x;
        dep[v]=dep[x]+1;
        dfs1(v);
    }
}
int calc(int x){
    int pr=0;
    for(int v:d){
        if(len[v]>x){
            for(int u:sz[v]){
                if(u!=v&&dep[u]<=len[v]-x) pr++;
            }
        }
    }
    vector<int>ans1(d.size());
    vector<int>ans2(d.size());
    int dia=0,l=0x3f3f3f3f,r=0;
    for(int i=0;i<d.size();i++){
        int dis=max(x-len[d[i]],0);
        dia=max(dia,i+len[d[i]]);
        int mid=dia/2;
        l=min(l,i+dis),r=max(r,i-dis);
        ans1[i]=max(mid-l,0)+max(r-mid,0)+1;
    }
    reverse(d.begin(),d.end());
    dia=0,l=0x3f3f3f3f,r=0;
    for(int i=0;i<d.size();i++){
        int dis=max(x-len[d[i]],0);
        dia=max(dia,i+len[d[i]]);
        int mid=dia/2;
        l=min(l,i+dis),r=max(r,i-dis);
        ans2[i]=max(mid-l,0)+max(r-mid,0)+1;
    }
    reverse(d.begin(),d.end());
    int ans=ans1[d.size()-1];
    for(int i=0;i<d.size()-1;i++){
        // cout<<ans1[i]<<" "<<ans2[d.size()-2-i]<<endl;
        ans=min(ans,ans1[i]+ans2[d.size()-2-i]);
    }
    // cout<<pr<<endl;
    return ans+pr;
}
void solve(){
    read(n);read(k);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        read(u),read(v);
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    for(int i=1;i<=n;i++) vis[i]=0;
    fa[1]=dep[1]=0;
    work.clear();
    dfs1(1);
    int s=1;
    for(int i=1;i<=n;i++){
        if(dep[i]>dep[s]) s=i; 
    }
    fa[s]=dep[s]=0;
    work.clear();
    dfs1(s);
    int t=1;
    for(int i=1;i<=n;i++){
        if(dep[i]>dep[t]) t=i;
    }
    // cout<<s<<" "<<t<<endl;
    d.clear();
    int tmp=t;
    while(tmp){
        d.push_back(tmp);
        vis[tmp]=1;
        tmp=fa[tmp];
        // cout<<tmp<<" ";
    }
    // cout<<endl;
    for(int v:d){
        mx=fa[v]=dep[v]=0;
        work.clear();
        dfs1(v);
        sz[v]=work;
        len[v]=mx;
    }
    int l=0,r=d.size(),ans=d.size();
    while(l<=r){
        int mid=l+r>>1;
        if(calc(mid)<=k) r=mid-1,ans=mid;
        else l=mid+1;
    }
    // assert(calc(0)==n);
    // for(int i=0;i<=d.size();i++){
    //     cout<<calc(i)<<endl;
    // }
    // cout<<calc(0)<<endl;
    writeln(ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(c);read(T);
    while(T--) solve();
    return 0;
}
/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/