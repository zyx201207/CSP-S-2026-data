#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
int tmp[30],res1_5;
bool vis[30];
void dfs(int now,int step){
    vis[now]=1;
    tmp[step]=a[now];
    if(step==m){
        int res=tmp[1];
        for(int i=1;i<=m;i++){
            res=res&tmp[i];
        }
        res1_5=max(res1_5,res);
        vis[now]=0;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,step+1);
        }
    }
    vis[now]=0;
}
signed main(){
    freopen("and.in","r",std.in);
    freopen("and.out","w",std.out);
    cin>>n>>m;
    int ma=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dfs(i,1);
        }
        cout<<res1_5<<endl;
        return 0;
    }
    if(n>20&&n<=2000&&m==1){
        cout<<ma<<endl;
        return 0;
    }
    if(n>20&&n<=2000&&m==n){
        int res7=a[1];
        for(int i=2;i<=n;i++){
            res7=res7&a[i];
        }
        cout<<res7<<endl;
        return 0;
    }
    if(n>20&&n<=2000&&m==2){
        int res8_10=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int res=a[i]&a[j];
                res8_10=max(res8_10,res);
            }
        }
        cout<<res8_10<<endl;
        return 0;
    }

}