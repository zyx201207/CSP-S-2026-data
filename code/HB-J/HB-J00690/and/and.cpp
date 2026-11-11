#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int book[N],a[N];
void dfs(int sum,int cnt){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++)
        if(book[i]==0){
            book[i]=1;
            dfs((sum & a[i]),cnt+1);
            book[i]=0;
        }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        book[i]=1;
        dfs(a[i],1);
        book[i]=0;
    }
    printf("%d",ans);
    return 0;
}
