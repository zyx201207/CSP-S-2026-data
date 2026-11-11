#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],t[1000005],ans[1000005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            if(t[a[j]]>1){
                for(int k=j-1;;k--){
                    if(t[a[k]]>0){
                        t[a[k]]--;
                    }
                    if(a[k]==a[j]){
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            ans[j]+=t[j];
            t[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
