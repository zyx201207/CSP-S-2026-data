#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200005];
void dfs(int s,int dep,int sum){
    if(dep==m+1){
        ma=max(ma,sum);
        return ;
    }
    for(int i=s+1;i<=n-m+dep+1;i++){
        dfs(i,dep+1,sum&a[i]);
    }
}
int f(int x){
    if(x>=1) return (1<<x)+f(x-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2005){
        dfs(0,1,f(30)+1);
        printf("%d",ma);
    }
    else{
        sort(a+1,a+n+1);
        printf("%d",a[n-m+1]);
    }
    return 0;
}
