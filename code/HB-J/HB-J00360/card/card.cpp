# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],t[M],pre[N],vis[N],f[N],ans[N],v[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(t[a[i]]==0) t[a[i]]=i;
        else           pre[i]=t[a[i]];
    }
    for(int st=1; st<=n; st++){
        for(int i=0; i<=n; i++) v[i]=vis[i]=0;
        for(int i=n; i>=1; i--){
            int j=i;
            while(pre[j]>=st) j=pre[j];
            vis[j]++,vis[i]--;
        }
        for(int i=st; i<=n; i++){
            vis[i]+=vis[i-1];
            if(vis[i]==0) v[a[i]]=1;
        }
        for(int i=1; i<=m; i++) ans[i]+=v[i];
    }
    for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
    return 0;
}
