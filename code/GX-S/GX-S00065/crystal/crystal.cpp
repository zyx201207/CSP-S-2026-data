#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        long long sum=0,cnt=0;
        for(int j=i-1;j>0;j--){
            cnt+=a[i]-a[j];
            if(cnt>m) break;
            sum++;
        }
        ans=max(ans,sum);
    }
    printf("%lld",ans+1);
    return 0;
}
