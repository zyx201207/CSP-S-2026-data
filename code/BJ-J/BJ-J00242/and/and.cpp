#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int ans=0;
int a[N];
int n,m;
void dfs(int x,int sum,int k){
    if(k>m)return;
    if(n-x+1<m-k)return;
    if(sum<=ans)return;
    if(x==n+1){
        if(k==m)ans=max(ans,sum);
        return;
    }
    for(int i=0;i<=1;i++){
        if(i==0)dfs(x+1,sum,k);
        else dfs(x+1,sum&a[x],k+1);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        printf("%d",ans);
    }else if(m==n){
        for(int i=1;i<=n;i++)ans&=a[i];
        printf("%d",ans);
    }else{
        dfs(1,(1LL<<31)-1LL,0);
        printf("%d",ans);
    }
    return 0;
}
