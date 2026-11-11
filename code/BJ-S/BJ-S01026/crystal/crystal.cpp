#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cha[500010],ans=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+1+n);
    for(long long i=2,tp,cnt;i<=n;i++){
        cnt=0,tp=0;
        for(int j=i;j>0;j--){
            if((tp+(a[i]-a[j]))<=m){
                tp+=(a[i]-a[j]);
                cnt++;
            }else continue;
        }ans=max(ans,cnt);
    }cout<<ans;
    return 0;
}