#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],p[200005],ans;
bool v[200005];
void dfs(int t){
    if(t==m+1){
        int r=a[p[1]];
        for(int i=2;i<t;i++)r&=a[p[i]];
        ans=max(ans,r);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            p[t]=i;
            dfs(t+1);
            v[i]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1);
    cout<<ans;
    return 0;
}
