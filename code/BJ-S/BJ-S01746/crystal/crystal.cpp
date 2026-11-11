#include<iostream>
#include<algorithm>
using namespace std;

#define int long long 
const int N=5e5+10;
int a[N];

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);int pt=0,sum=0,v=0;
    for(int i=1;i<=n;i++) {
        sum+=((i-1)-(pt+1)+1)*(a[i]-a[i-1]);
        while(sum>m) {
            sum-=a[i]-a[pt+1];
            pt++;
        }
        v=max(v,i-pt);
        // cout<<pt<<' '<<i<<endl;
    }cout<<v<<endl;
    return 0;
}