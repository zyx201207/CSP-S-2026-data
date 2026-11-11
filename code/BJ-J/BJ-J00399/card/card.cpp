#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
int a[N],sum[N],vis[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        if(sum[a[i]]==0)sum[a[i]]=1;
        else{
            vis[i]=0;
            for(int j=i+1;j<=n&&a[j]!=a[i];j++){
                if(vis[i])continue;
                sum[a[j]]=0;vis[j]=1;
            }
        }
        for(int j=1;j<=m;j++)if(sum[j])ans[j]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}