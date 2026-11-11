#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005][40],c[40],cnt;
void dfs(int x,int ans,int now){
    if(!x){
        printf("%d",ans);
        return;
    }
    for(int i=1;i<=now;i++){
        if(b[i][x]){
            c[x]++;
        }
    }
    if(c[x]>=m){
        cnt=0;
        for(int i=1;i<=now;i++){
            if(b[i][x]==1){
                cnt++;
                for(int j=1;j<=31;j++){
                    b[cnt][j]=b[i][j];
                }
            }
        }int o=1;
        for(int j=1;j<x;j++){
            o*=2;;
        }
        dfs(x-1,ans+o,cnt);
    }else{
        dfs(x-1,ans,now);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=31;j++){
            b[i][j]=a[i]%2;
            a[i]/=2;
        }
    }
    dfs(31,0,n);
}
