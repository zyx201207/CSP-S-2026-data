#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=500005;
LL n,m,a[N],b[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
    cout<<upper_bound(b+1,b+n+1,m)-b-1;
    return 0;
}
