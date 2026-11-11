#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],nw[300005],ans[300005];
bool b[300005];
vector<int> p[500005];
int dfs(int x,int flag){
    int d=1,xx=0;
    for(int i=0;i<p[x].size();i++){
        if(!b[a[p[x][i]]]){
            b[a[p[x][i]]]=1;
            xx=dfs(p[x][i],1);
            b[a[p[x][i]]]=0;
        }
        else{
            xx=dfs(p[x][i],0);
        }
        d+=xx;
    }
    if(flag) ans[a[x]]+=d;
    return d;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        if(!nw[a[i]]){
            nw[a[i]]=i;
            p[i+1].push_back(i);
        }
        else{
            p[nw[a[i]]].push_back(i);
            nw[a[i]]=i;
        }
    }
    dfs(n+1,0);
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}