#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
int n,m,a[N],ans=0;
void dfs(int pos,int sum,int num){
    if(pos==n+1){
        if(sum==m) ans=max(ans,num);
        return;
    }
    if(sum>m) return;
    //if(m-sum>n-pos) return;
    dfs(pos+1,sum,num);
    dfs(pos+1,sum+1,num&a[pos]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    }
    else if(m==n){
        ans=inf;
        for(int i=1;i<=n;i++) ans&=a[i];
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else dfs(1,0,inf);
    printf("%d\n",ans);
    return 0;
}
