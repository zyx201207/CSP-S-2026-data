#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],lb,ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=lb;k++){
                if(b[k]==a[j]){
                    for(int l=k;l<=lb;l++) b[l]=0;
                    lb=k;
                }
            }
            lb++;
            b[lb]=a[j];
        }
        for(int j=1;j<=lb;j++) ans[b[j]]++;
        lb=0;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
