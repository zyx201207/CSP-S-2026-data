#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,INF=LONG_MAX;
int n,m,a[N],ans;
vector<int> dp(N);
bool flag=true;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=sum){
            flag=false;
        }
    }

        sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            int j=i,cnt=m;
        while(true){
            if(a[j+1]-a[j]>cnt or j==n){
                dp[i]=j-i+1;
                break;
            }else{
                cnt-=a[j+1]-a[j];
                j++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;


    return 0;
}
