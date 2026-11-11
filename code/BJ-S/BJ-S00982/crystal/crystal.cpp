#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int N=502026;
ll s[N],a[N];
long long aans(long long i,long long j){
    return (j-i)*a[j]-s[j-1]+s[i-1];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long l=1,r=1;
    long long ans=1;
    while(l<=n&&r<=n){
        if(aans(l,r)<=m) ans=max(ans,r-l+1),r++;
        else l++;
    }
    cout<<ans;
    return 0;
}
