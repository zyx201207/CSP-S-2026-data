#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define w(x) cerr<<#x<<':'<<x<<endl
#define dbg cerr<<"\n----------------\n"
#define fi first
#define sc second
#define pii pair<int,int>
const int inf=3e18;
const int mod=998244353;
const int N=5e5+5;
int T,n,m,x,y,z,l,r,L,cnt,now,sum,ans,len;
int a[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(),cout.tie();
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
//    cin>>T;
//    while(T--){
//
//    }
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    l=1;
    ans=1;
    for(int i=1;i<=n;i++){
        m-=(i-l)*(a[i]-a[i-1]);
        while(m<0 && l<i) m+=a[i]-a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    cerr<<endl<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
