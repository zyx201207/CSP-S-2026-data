#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    LL n,m;
    LL cnt=1;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    LL ans=a[1];
    for(LL i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            ans=a[i];
            cnt++;
        }
    }
    if(cnt==1){
        cnt=0;
    }
    for(LL i=1;i<=m-cnt;i++){
                ans&=a[i];
    }
    cout<<ans;
    return 0;
}
