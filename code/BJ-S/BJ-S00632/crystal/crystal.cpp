#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,ans;
long long a[N];
long long d[N];
long long sum[N];//houzhuihe
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    for(int i = n;i>=1;i--){
        sum[i]=sum[i+1]+d[i];
    }
    //cnt+=sum[j+1]-sum[i+1]
    for(int i = n;i>=1;i--){
        long long cnt=0;
        for(int j = i;j>=1;j--){
            cnt+=sum[j+1]-sum[i+1];
            if(cnt>m){
                ans=max(ans,(long long)(i-j));
                break;
            }
        }
        if(cnt<=m){
            ans=max(ans,(long long)(i));
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
}
