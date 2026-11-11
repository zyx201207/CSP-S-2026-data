#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int n;
ll m;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll sum=0;
    int ans=1;
    int l=1;
    for(int i=2;i<=n;i++){
        ll p=a[i]-a[i-1];
        sum=sum+p*1ll*(1ll*(i-l));
        while(sum>m&&l<i){
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}
