#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int n,m,zhch=0;
int a[N],cnt[M],zhuo[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(cnt,0,sizeof(cnt));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=zhch;k++){
                if(zhuo[k]==a[j]){
                    zhch=k-1;
                    break;
                }
            }
            zhch++;
            zhuo[zhch]=a[j];
        }
        for(int k=1;k<=zhch;k++){

            cnt[zhuo[k]]++;
        }

        zhch=0;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
