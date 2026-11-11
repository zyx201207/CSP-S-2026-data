#include<bits/stdc++.h>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define ll long long
using namespace std;

const int N=500005;
int n;
ll m,a[N];

signed main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    forto(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    __int128 cost=0;int j=1,ans=0;
    a[0]=a[1];
    forto(i,1,n){
        cost+=(__int128)(i-j)*(a[i]-a[i-1]);
        while(cost>m){
            cost-=a[i]-a[j],j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
    return 0;
}