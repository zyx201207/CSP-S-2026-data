#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005,M=300005;
int n,m,a[N],c[N],ans[M],cnt_over,cnt_a[M];
bool vis[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(cnt_a[a[i]]++==1){
            cnt_over++;
        }
    }
    for(int l=1;l<=n;l++){
        if(cnt_over==0){
            for(int i=l;i<=n;i++){
                ans[a[i]]+=cnt_a[a[i]]*(i-l+1);
            }
            break;
        }
        //memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        int it=0;
        for(int i=l;i<=n;i++){
            while(it&&vis[a[i]]){
                ans[c[it]]--;
                vis[c[it--]]=0;
            }
            ans[a[i]]++;
            c[++it]=a[i];
            vis[a[i]]=1;
        }
        if(--cnt_a[a[l]]==1){
            cnt_over--;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
