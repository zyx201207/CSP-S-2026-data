#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int ans=0,res,tmp;
int a[N];

void dfs(int i,int j,int step){
    if(i==j){
        if(res>step){
            res=step;
            tmp=1;
        }else if(res==step)tmp++;
        return ;
    }
    for(int k=i+1;k<=j;k++){
        if(a[k]-a[i]<=m){
            dfs(k,j,step+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        memset(a+1,0,sizeof a);
        ans=0;

        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                res=INT_MAX;tmp=1;
                dfs(i,j,0);
                if(tmp==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
