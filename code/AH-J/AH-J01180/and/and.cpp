#include<stdio.h>
#include<vector>
int n,m;
int ans=0;
int sum=0;
std::vector<bool> vis;
std::vector<int> a;
void dfs(int dep,int sum){
    if(dep==m){
        ans=std::max(ans,sum);
        return;
    }
    for(int i=dep;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            int n_sum;
            if(dep==0){
                n_sum=a[i];
            }
            else{
                n_sum=sum&a[i];
            }
            dfs(dep+1,n_sum);
            vis[i]=0; 
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    vis.resize(n+1);
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    printf("%d\n",ans);
    return 0;

}