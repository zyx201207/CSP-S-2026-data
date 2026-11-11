#include <bits/stdc++.h>
using namespace std;
long long n,m;
int tong[200020],ans[200020],a[200020];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        memset(tong,0,sizeof tong);
        for(int j=i,lp=1;j<=n;j++){
            if(tong[a[j]]!=0){
                lp=tong[a[j]]+1;
                for(int k=1;k<=m;k++){
                    if(k==a[j]) continue;
                    if(tong[k]>=tong[a[j]]){
                        tong[k]=0;
                    }
                }continue;
            }if(!tong[a[j]]){
                tong[a[j]]=lp;
                lp++;
            }
        }for(int j=1;j<=m;j++){
            if(tong[j]){
                ans[j]++;
            }
        }

    }for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
