#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,m;
int a[N],lst[N],cnt[N],ans[N];
vector<int>e[N];
void dfs(int u,int fa){
    ans[u]=cnt[u];
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        ans[u]+=ans[v];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lst[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        int j=a[lst[i]+1];
        e[i].push_back(j);
        e[j].push_back(i);
    }
    dfs(a[n],0);
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}
//waiting for somebody back
