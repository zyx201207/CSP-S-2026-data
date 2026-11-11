#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[2][200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1||m==1){
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1,greater<long long>());
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
