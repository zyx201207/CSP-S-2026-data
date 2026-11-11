#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int n,m;
bool vis[N];
long long a[N],dp[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}
