#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],d[N],pre[N],ans=1,check=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[2]-a[1]) check=0;
    }
    sort(a+1,a+1+n);
    if(check){
        int cnt=0;
        for(int i=1;i<=n;++i){
            cnt+=i*(a[2]-a[1]);
            if(cnt<=m){
                ans=max(ans,i+1);
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;++i){
        pre[i+1]=0;
        for(int j=i;j>=1;--j){
            d[j]=a[i]-a[j];
            pre[j]=pre[j+1]+d[j];
            if(pre[j]<=m){
                ans=max(ans,i-j+1);
            }else{
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
