#include <bits/stdc++.h>
using namespace std;
int n,m,step;
int a[500005];
int zhuo[300005],ans[300005],wei[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        if (i != 1){
            for (int j = 1;j < step;j++) wei[zhuo[j]]=0;
            for (int j = 1;j < step;j++) zhuo[j]=0;
        }
        step=1;
        for (int j = i;j<=n;j++){
            if (wei[a[j]]==0){
                zhuo[step] = a[j];
                wei[a[j]]=step;
                step++;
            }
            else{
                int ss = wei[a[j]]+1;
                for (int k = ss;k < step;k++){
                    wei[zhuo[k]]=0;
                    zhuo[k]=0;
                }
                step=ss;
            }
        }
        for (int j = 1;j < step;j++) ans[zhuo[j]]++;
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
