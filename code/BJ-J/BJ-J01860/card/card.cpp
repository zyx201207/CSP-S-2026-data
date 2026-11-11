#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],vis[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof vis);
        for(int j=i;j<=n;++j){
            if(vis[a[j]]>0){
                for(int k=vis[a[j]];k<j;++k) vis[a[k]]=0;
                vis[a[j]]=j;
            }else if(vis[a[j]]==0) vis[a[j]]=j;
        }
        for(int j=1;j<=m;++j) if(vis[j]>0) ++ans[j];
    }
    for(int i=1;i<=m;++i){
        if(i!=m) cout<<ans[i]<<' ';
        else cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}