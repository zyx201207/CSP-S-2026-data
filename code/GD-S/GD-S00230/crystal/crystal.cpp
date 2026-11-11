#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n,m;
LL a[500010];
LL ans=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    LL l=1;
    for(LL i=2;i<=n;i++){
        m-=(a[i]-a[i-1])*(i-l);
        while(m<0){
            m+=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}