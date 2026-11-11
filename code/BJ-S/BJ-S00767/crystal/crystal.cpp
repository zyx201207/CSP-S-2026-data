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
const int MAXN = 5e5+10;
int n,m,a[MAXN];
bool check(int x) {
    int sum = 0;rep(i,1,x) 
    sum += a[i];rep(l,1,n) {
        int r = l+x-1;if(r>n) break;
        if(a[r]*x-sum<=m) return true;
        sum -= a[l],sum += a[r+1];
    }return false;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int l = 1,r = n,res = l;
    while(l<=r) { int mid = (l+r)/2;
        if(!check(mid)) r = mid-1;
        else l = mid+1,res = mid;
    }cout<<res<<endl;
    return 0;
}