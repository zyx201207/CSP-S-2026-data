#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010],ans[300010];
int vis[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            vis[j] = 0;
        }
        for(int j = i;j <= n;j++){
            if(vis[j] == -1){
                continue;
            }
            for(int k = j + 1;k <= n;k++){
                if(a[k] == a[j]){
                    //cout<<j <<" "<<k<<endl;
                    for(int t = j;t < k;t++){
                        vis[t] = -1;
                    }
                    break;
                }
            }
        }
        for(int j = i;j <= n;j++){
            if(vis[j] == 0){
                ans[a[j]]++;
                //cout<<ans[a[j]]<<endl;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
