#include<bits/stdc++.h>
#define re register
using namespace std;
int n,m;
int a[200010];
int sum;
void dfs(int b[],int p,int step,int cnt){
    if(step==m){
        sum=max(sum,cnt);
        return;
    }
    for(re int i=p;i<=n;i++){
        b[step+1]=a[i];
        dfs(b,i,step+1,(cnt&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int maxx=0,sum=0;
    for(re int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum=(sum&a[i]);
        maxx=max(maxx,a[i]);
    }
    if(m==1||maxx<4){
        printf("%d",maxx);
        return 0;
    }
    if(m==n-1){
        int masx=0;
        for(re int i=1;i<=n;i++)masx=max(masx,(sum&a[i]));
        printf("%d",masx);
        return 0;
    }
    int b[200010];
    for(re int i=1;i<=n;i++){
        b[1]=a[i];
        dfs(b,i,1,a[i]);
    }
    printf("%d",sum);
    return 0;
}
