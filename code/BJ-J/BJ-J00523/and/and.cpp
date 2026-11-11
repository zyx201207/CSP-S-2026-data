#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100005],p[100005];
void dfs(int s,int n,int m11){
    if(m11==m+1){
        int y=a[p[1]];
        for(int i=2;i<=m;i++){
            y&=a[p[i]];
        }
        ans=max(ans,y);
        return;
    }
    for(int i=s+1;i<=n;i++){
        p[m11]=i;
        dfs(i,n,m11+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,n,1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
