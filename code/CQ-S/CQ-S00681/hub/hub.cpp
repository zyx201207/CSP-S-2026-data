#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,T,fa[maxn][25],dep[maxn];
vector<int> t[maxn];
vector<int> tmp;
int n,k,fin;
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i:t[x]){
        if(i==f) continue;
        dfs(i,x);
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
void work(int x){
    if(n-x+1<k-tmp.size()) return;
    if(tmp.size()>k) return;
    if(x==n+1){
        int res=0;
        for(int i=1;i<=n;i++){
            int ans=n;
            for(int j:tmp){
                ans=min(ans,dep[i]+dep[j]-2*dep[LCA(i,j)]);
            }
            res=max(res,ans);
        }
        fin=min(fin,res);
        return;
    }
    tmp.push_back(x);
    work(x+1);
    tmp.pop_back();
    work(x+1);
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    if(c>=1&&c<=3){
        dfs(1,0);
        fin=n;work(1);
        cout<<fin<<"\n";
    }else if(c>=13&&c<=14){
        if(k%2) cout<<((n+1)/2-k)/4<<"\n";
        else cout<<((n+1)/2-k)/4+1<<"\n";
    }
    for(int i=1;i<=n;i++) t[i].clear();
    tmp.clear();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}