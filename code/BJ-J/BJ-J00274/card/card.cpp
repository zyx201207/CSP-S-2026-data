#include <bits/stdc++.h>
using namespace std;
int n,m,a[5050],b[3030],k[3030],cnt[3030];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[a[j]]++;
        }
        bool f=true;
        int flag=-1;
        for(int j=i;j<=n;j++){
            if(!f&&flag==a[j]){
                f=true;
                flag=-1;
            }
            if(!f){
                b[a[j]]--;
                continue;
            }
            if(b[a[j]]>1){
                f=false;
                flag=a[j];
                b[a[j]]--;
                continue;
            }
            b[a[j]]--;
            if(f){
                k[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(k[j])cnt[j]++;
            k[j]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
