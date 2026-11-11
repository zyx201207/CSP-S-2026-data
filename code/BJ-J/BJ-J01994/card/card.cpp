#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[300010];
bool vis[300010];
int kskbl[300100];
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1+i-1;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=1;
                kskbl[a[j]]=j;
            }
            else {
                for(int k=kskbl[a[j]];k<j;k++){
                    vis[a[k]]=0;
                }
                vis[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j])sum[j]++;
        }
        memset(vis,0,sizeof(vis));
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}

