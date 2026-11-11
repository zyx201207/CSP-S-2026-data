#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans;
int sum;
int cnt;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if((a[n]-a[1])*(n-1))<=m){
        cout<<n<<endl;
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(ans>=i) break;
        sum=0;
        cnt=0;
        for(int j=i;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum<=m){
                cnt++;
                ans=max(ans,cnt);
            }else{
                ans=max(ans,cnt);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

