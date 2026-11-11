#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[505000];
int a[505505];
int noi[505][505];
int ioi[505000][3];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool qp=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]<a[i-1]){
            qp=0;
        }
    }
    if(qp){
        for(int i=1;i<=n;i++){
            cnt[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
        return 0;
    }
    if(n<=5000&&m<=3000){
        for(int i=1;i<=n;i++){
           for(int j=i;j<=n;j++){
                noi[i][a[j]]++;
                if(noi[i][a[j]]==2){
                    for(int k=j-1;k>=i;k--){
                        if(noi[i][a[k]]>0)
                        noi[i][a[k]]--;
                        if(a[k]==a[j])break;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            int ans=0;
            for(int j=1;j<=n;j++){
                ans+=noi[j][i];
            }
        cout<<ans<<' ';
        }
        return 0;
    }
    return 0;
}
