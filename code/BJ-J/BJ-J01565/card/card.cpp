#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long beg=a[i],las=a[n],zb=i,zl=n;
        for(long long j=n;j>i;j--){
            if(a[j]==beg){
                zb=j;
                break;
            }
        }
        for(long long j=n-1;j>=zb;j--){
            if(a[j]==las)zl=j;
        }
        for(long long j=zb;j<zl;j++){
            ans[a[j]]++;
        }
        ans[a[n]]++;
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
