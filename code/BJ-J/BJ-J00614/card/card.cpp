#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],ans[1000005];
int vis[100005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                //cout<<'%'<<vis[a[j]]<<endl;
                for(int k=1;k<=m;k++){
                    if(vis[k]<vis[a[j]])
                    vis[k]=0;
                }

            }
            for(int k=1;k<=m;k++){if(vis[k])vis[k]++;}
            vis[a[j]]=1;
            //for(int k=1;k<=m;k++){cout<<vis[k]<<' ';}cout<<endl;
        }
        for(int j=1;j<=m;j++){
            if(vis[j])ans[j]++;
        }//cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
