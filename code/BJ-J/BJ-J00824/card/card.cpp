#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],mp[300010],b[500010];
inline void solve(int x){
    memset(mp,0,m*4+20);
    memset(b,0,n*4+20);
    int tot=0;
    mp[a[x]]=++tot;
    b[tot]=a[x];
    for(int i=x+1;i<=n;i++){
        if(mp[a[i]]){
            for(int j=mp[a[i]];j<=tot;j++){
                mp[b[j]]=0;
            }
        }
        mp[a[i]]=++tot;
        b[tot]=a[i];
    }
    for(int i=1;i<=m;i++){
        if(mp[i])ans[i]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
