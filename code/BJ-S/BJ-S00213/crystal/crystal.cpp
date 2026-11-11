#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int p=1,ans=0;
    for(int i=1;i<=n;i++){
        while(p<=i&&1ll*(i-p+1)*a[i]-sum[i]+sum[p-1]>m)p++;
        ans=max(ans,i-p+1);
    }
    cout<<ans<<"\n";
    return 0;
}