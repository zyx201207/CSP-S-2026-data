#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m,a[N],dp[N][N],cnt[N],ans;//cnt:用了几个
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(a[i],ans);
    }
    dp[0][0]=a[1];

    cout<<ans;
    return 0;
}
