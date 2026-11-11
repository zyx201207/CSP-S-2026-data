#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int a[N];
ll sum[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    int l=1,mx=1;
    for(int i=2;i<=n;++i){
        while(1ll*(i-l+1)*a[i]-sum[i]+sum[l-1]>m)l++;
        mx=max(mx,i-l+1);
    }
    cout<<mx;
    return 0;
}
//14:43
