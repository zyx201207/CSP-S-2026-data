#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+10;
int n,m,a[N],ch[N],dp[N][N],cnt=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) ch[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=(ch[j]*(j-i))+dp[i][j-1];
            if(m>=dp[i][j]) cnt=max(j-i+1,cnt);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
