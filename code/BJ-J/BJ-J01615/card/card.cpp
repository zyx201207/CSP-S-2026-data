#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            num[a[j]]++;
            for (int k=n;k>j;k--){
                if (a[k]==a[j]){
                    j=k;
                    break;
                }
            }
        }
    }
    for (int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
