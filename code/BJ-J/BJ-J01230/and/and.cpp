#include<bits/stdc++.h>
#define int long long
#define maxn 16005
using namespace std;
int n,m;
int a[200005];
int dp[maxn][maxn];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(n>2000){
        int maxx=-1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
        return 0;
    }
    int maxi;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=2e31-1;
    }
    for(int k=1;k<=n;k++){
        dp[k][1]=a[k];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=2;j--){
                if(i!=k)
                    dp[k][j]=max(dp[k][j],dp[k][j-1]&a[i]);
            }
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
