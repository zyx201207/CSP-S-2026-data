#include<iostream>
using namespace std;
long long a[200005],ans=0;
int m,n;

void dfs(int now,long long tot,int cnt){
    if(cnt==m) ans=max(ans,tot);
    for(int i=now+1;i<=n;i++){
        int tmp=tot & a[i];
        if(tmp>ans) dfs(i,tmp,cnt+1);
    }
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>> n >> m;
    for(int i=1;i<=n;i++) cin>> a[i];
    dfs(0,2147483647,0);
    cout<< ans;
    return 0;
}
