#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],cnt[200005],zhuo[200005];
bool f=true;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]>a[i-1]){
            f=false;
        }
    }
    for(int i=1;i<=n;i++){
        memset(zhuo,0,sizeof(zhuo));
        for(int j=i;j<=n;j++){
            bool f=false;
            for(int k=1;k<=n;k++){
                if(zhuo[k]==a[j]){
                    zhuo[k]=a[j];
                    for(int l=k+1;l<=n;l++){
                        zhuo[l]=0;
                    }
                    f=true;
                    break;
                }
            }
            if(!f){
                for(int l=1;l<=n;l++){
                    if(zhuo[l]==0){
                        zhuo[l]=a[j];
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(zhuo[j]!=0){
                cnt[zhuo[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}