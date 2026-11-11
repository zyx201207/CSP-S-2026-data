#include <bits/stdc++.h>
#define lovely ios::sync_with_stdio(false),cin.tie(0)
#define ly cin
#define lzy cout
using namespace std;
const int maxn=5e5+10,maxm=3e5+10;
int a[maxn];
int cnt[maxm];
int d[maxm];
bool vis[maxn];
int n,m;
int main(){
    freopen("card.in", "r",stdin);
    freopen("card.out","w",stdout);
    lovely;
    ly>>n>>m;
    for(int i=1;i<=n;i++)ly>>a[i];
    for(int i=1;i<=n;i++){
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(!d[a[j]])d[a[j]]=j;
            else{
                for(int k=d[a[j]];k<=j-1;k++){
                    vis[k]=false;
                    d[a[k]]=0;
                }
                d[a[j]]=j;
                for(int k=1;k<=j-1;k++)if(vis[k])d[a[k]]=k;
            }
            vis[j]=true;
        }
        for(int j=i;j<=n;j++)if(vis[j])cnt[a[j]]++;
    }
    for(int i=1;i<=m;i++)lzy<<cnt[i]<<" ";
    return 0;
}