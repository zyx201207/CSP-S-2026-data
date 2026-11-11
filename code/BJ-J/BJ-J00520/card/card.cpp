#include<bits/stdc++.h>
using namespace std;
int ans[300003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool ok=true;
    int a[n+3];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])ok=false;
    }
    if(ok){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]&&cnt!=0)cout<<cnt<<" ";
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(find(a+j+1,a+n+1,a[j])==a+n+1){
                ans[a[j]]++;
            }
            else{
                for(int k=n;k>j;k--){
                    if(a[k]==a[j]){
                        j=k;
                        ans[a[j]]++;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}