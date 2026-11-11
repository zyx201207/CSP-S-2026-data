#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;
int n,m;
int a[MAXN],cnt[MAXM];
int ucg[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ucg[i]=a[i];
    }

    for(int i=1;i<=n;i++){//游戏局数
        for(int u=1;u<=n;u++){//初始化变量
            ucg[u]=a[u];
        }
        for(int j=i;j<=n;j++){//所有的牌
            for(int q=i;q<=j;q++){//每发一张牌，检查是否与之前发过的一样
                if(ucg[q]==ucg[j] && q!=j){
                    ucg[q]=ucg[j];
                    for(int w=q+1;w<=j;w++){//归零
                        ucg[w]=0;
                    }
                }else if(ucg[q]!=ucg[j]){
                    continue;
                }
            }
        }
        for(int gn=i;gn<=n;gn++){
            for(int gm=1;gm<=m;gm++){
                if(ucg[gn]==gm){
                    cnt[gm]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
