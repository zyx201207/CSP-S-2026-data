#include <bits/stdc++.h>
using namespace std;
//const int N=5000;
long long n,m;
long long a[5009],b[5009];
long long dp[5009][5009];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i+1;j--){
            dp[i][j]=a[j]-a[i];

            //cout<<dp[i][j]<<" ";
        }
        //cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i+1;j--){
            swap(dp[n-i][j+1],dp[n-j][i+1]);
        }
    }
    int maxx=-10;
    for(int i=1;i<=n;i++){
            int cnt=0,p=1,l=0;
        for(int j=n;j>=i+1;j--){
            cnt+=dp[i][j];
            l++;
            if(cnt>m){
                cnt-=dp[j][p];
                p++;
                l--;
            }
            //cout<<dp[i][j]<<" ";
        }
        maxx=max(maxx,l);
        //cout<<'\n';
    }
    cout<<maxx+1;
    //bububu,wo wu yi shi feng nu de.Linux "wo ai ni".
    //wo yao shang mi huo xing wei da shang,diao yu qu TvT.
    //feropen("crystal.in","r",stdin);
    return 0;
}

