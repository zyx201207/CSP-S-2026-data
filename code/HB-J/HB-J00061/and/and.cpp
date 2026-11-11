#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],c[N],ans;
void dfs(int i){
    if(i==n+1){
        int sum=0,x=0;
        for(int j=1;j<=n;j++){
            if(c[j]){
                sum=a[j];
                break;
            }
        }
        for(int j=1;j<=n;j++){
            if(c[j]){
                sum=sum&a[j];
                x++;
            }
        }
        if(x==m){
            ans=max(ans,sum);
        }
        return;
    }
    c[i]=0;
    dfs(i+1);
    c[i]=1;
    dfs(i+1);
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1);
    printf("%d\n",ans);

    return 0;
}
