#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define per(i,a,b) for(int i = (a);i>=(b);i--)
#define endl '\n'
const int MAXN = 2e5+10;
int n,a[MAXN],d[MAXN],m;char c[MAXN];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;rep(i,1,n)
        cin>>a[i]>>c[i],m += a[i];
    int sum = 0;rep(i,1,n) {
        if(sum<=(m+1)/2&&(m+1)/2<=sum+a[i]) {
            per(j,n+1,i+1) a[j] = a[j-1],c[j] = c[j-1];
            if(m%2) { per(j,n+2,i+2) a[j] = a[j-1],c[j] = c[j-1];
                a[i+2] = sum+a[i]-(m+1)/2;c[i+2] = c[i];
                a[i+1] = 1;c[i+1] = c[i];n += 2;
                a[i] = (m+1)/2-sum-1;c[i] = c[i];
            } else a[i+1] = sum+a[i]-m/2,a[i] = m/2-sum,
            c[i+1] = c[i],n++;break;}sum += a[i];
    }//rep(i,1,n) cout<<a[i]<<' '<<c[i]<<endl;
    int ans = 0,l = 1,r = m;
    int i = 1,j = n;while(l<=r) {
        // cout<<l<<' '<<r<<' '<<i<<' '<<j<<endl;
        int tmp = min(a[i],a[j]);
        l += tmp;r -= tmp;
        if(c[i]!=c[j]) ans += tmp;
        a[i] -= tmp,a[j] -= tmp;
        if(!a[i]) i++;if(!a[j]) j--;
        // cout<<l<<' '<<r<<' '<<i<<' '<<j<<endl<<endl;
    }cout<<ans<<endl;
    return 0;
}