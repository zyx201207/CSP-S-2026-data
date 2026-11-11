#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200001],w[31],v[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
// vector<bool>bi[200001];
int dp[31][200001],ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    m=n-m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int now=a[i],ii=0;
        while(now){
            // bi[i].push_back(1-now%2);
            w[ii++]+=(1-now%2);
            now/=2;
        }
        while(ii<=30){
            ++w[ii++];
        }
    }
    for(int i=0;i<=30;++i){
        for(int j=w[i];j<=m;++j){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			// cout<<dp[i][j]<<':'<<v[i]<<' ';
        }
        // cout<<'\n';
    }
    for(int i=0;i<=30;++i){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
