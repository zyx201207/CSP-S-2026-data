#include<bits/stdc++.h>
using namespace std;
int ans[300005];
int n,m,a[500005],tmp[500005];
int cnt=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=i;j<=n;j++){
            cnt++;
            a[cnt]=tmp[j];
            for(int k=cnt;k>=1;k--){
                if(a[k]==a[j]){
                    cnt=k;
                }
            }
        }
        for(int k=1;k<=cnt;k++){
            ans[a[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
