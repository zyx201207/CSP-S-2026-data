#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int ans[100005];
int cnt[100005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int j=1;j<=n;j++){
        memset(cnt,0,sizeof(cnt));
        memset(vis,false,sizeof(vis));
        for(int i=j;i<=n;i++){
            if(cnt[arr[i]]!=0){
                for(int k=cnt[arr[i]];k<=i;k++){
                    vis[arr[k]]=false;
                    cnt[arr[k]]=0;
                }
            }
            vis[arr[i]]=true;
            cnt[arr[i]]=i;
        }
        for(int i=1;i<=m;i++)
            if(vis[i]) ans[i]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
