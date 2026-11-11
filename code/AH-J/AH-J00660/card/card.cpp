#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],last[M],cnt[M],to[M],in[M],ans[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        last[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        if(i!=a[n]){
            //i -> a[last[i]+1];
            to[i]=a[last[i]+1];
            in[to[i]]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=m;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        ans[u]+=cnt[u];
        if(u==a[n]) break;
        int v=to[u];
        ans[v]+=ans[u];
        in[v]--;
        if(in[v]==0){
            q.push(v);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
I want to AK csp_j !
*/
