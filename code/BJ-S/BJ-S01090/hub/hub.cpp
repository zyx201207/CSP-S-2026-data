#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N = 2e6+5,M=2e6,Q=2e3+5;
int c,t,n,k;
int a[N];
vector<int>g[N];
int dfs(int u,int fa){
    if(a[u]==1)return 0;
    int mn = 1e9;
    for(auto v:g[u]){
        if(v==fa)continue;
        mn=min(dfs(v,u)+1,mn);
    }
    return mn;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 1;i<=n;i++)if(i<=k)a[i]=1;
        for(int i = 1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans =1e9;
        do{
            int cnt = 0;
            for(int i = 1;i<=n;i++){
                //printf("%d ",a[i]);
                cnt=max(cnt,dfs(i,0));
            }
            ans=min(ans,cnt);
        }while(prev_permutation(a+1,a+n+1));
        printf("%d\n",ans);
    }
    
}//100+100+24+5=249