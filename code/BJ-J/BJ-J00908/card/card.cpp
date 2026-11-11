#include<bits/stdc++.h>
using namespace std;
//I CAN AK CCF CSP
int a[500010];
int zhuo[350010];
int ans[300010];
int main(){
    freopen("card4.in","r",stdin);
    freopen("card4.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int ding=0;
        for(int j=i;j<=n;j++){
            bool have=0;
            for(int k=ding;k>0;k--){
                if(a[j]==zhuo[k]){
                    ding=k;
                    have=1;
                    break;
                }
            }
            if(!have){
                zhuo[++ding]=a[j];
            }
        }
        for(int j=1;j<=ding;j++){
            ans[zhuo[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
