#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn;

void dfs(int u,int pre,long long cnt){
    if(u==m+1){
        maxn=max(maxn,cnt);
        return ;
    }
    for(int i=pre+1;i<=n;i++){
        if(u==1){
            dfs(u+1,i,a[i]);
        }else{
            dfs(u+1,i,(cnt&a[i]));
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0,0);
    cout<<maxn;
    return 0;
}
