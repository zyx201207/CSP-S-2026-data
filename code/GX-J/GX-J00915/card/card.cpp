#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N],mx[N];
bool vis[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mx[a[i]]=i;
    }
    for(int L=1;L<=n;++L){
        for(int i=1;i<=m;++i) vis[i]=0;
        for(int i=mx[a[L]];i<=n;i++){
            int x=a[i];
            vis[x]=1;
            if(i!=mx[x]){
                i=mx[x];
                continue;
            }
        }
        for(int i=1;i<=m;++i){
            if(vis[i]) ans[i]++;
        }
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
    return 0;
}
