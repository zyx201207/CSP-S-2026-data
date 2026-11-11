#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],lst[M],nxt[M],cnt[M],ans[M];
vector <int> e[N];

int dfs(int u){
    if(ans[u]) return ans[u];
    ans[u]=cnt[u];
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        ans[u]+=dfs(v);
    }
    return ans[u];
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        if(!lst[a[i]]) lst[a[i]]=i;
    }
    for(int i=n;i>=1;i--){
        nxt[a[i]]=lst[a[i]]+1;
        if(lst[a[i]]==i) e[a[i+1]].push_back(a[i]);
    }
    for(int i=1;i<=m;i++) cout<<dfs(i)<<' ';
    //I love Aether & Lumine!!!
}
