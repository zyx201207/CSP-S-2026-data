#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
bool vis[N];
int a[N];
int res[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                memset(vis,0,sizeof(vis));
            }
            vis[a[j]]=true;
        }
        for(int j=i;j<=m;j++){
            if(vis[a[j]]) res[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
