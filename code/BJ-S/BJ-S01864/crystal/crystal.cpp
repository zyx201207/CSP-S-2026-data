#include<bits/stdc++.h>//T1
#define int long long
using namespace std;
const int N=5e5+13;
int n,m,a[N],f[N],sum[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        if(a[i]*(i-1)-sum[i-1]<=m)f[i]=i;
        else{
            for(int j=i-f[i-1];j<i;j++){
                if(a[i]*(i-j)-sum[i-1]+sum[j-1]<=m){
                    f[i]=i-j+1;
                    break;
                }
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
