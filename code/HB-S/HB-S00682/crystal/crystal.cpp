#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using std::cin;
using std::cout;
using std::cerr;
using pii = std::pair<int,int>;
template<typename T>using vec = std::vector<T>;
template<typename T>using vec2 = vec<vec<T>>;
template<typename T1,typename T2>using map = __gnu_pbds::gp_hash_table<T1,T2>;
constexpr int inf = 1e12+7;
struct Solve{
    int n,m;
    vec<int>a;
    vec<int>pre;
    bool check(int len){
        int res = 0;
        for(int l=1,r=len;r<=n;++l,++r){
            res = len * a[r] - pre[r] + pre[l-1];
            if(res <= m)return true;
        }
        return false;
    }
    Solve(){
        cin>>n>>m;
        a.assign(n+1,0);
        pre.assign(n+1,0);
        for(int i=1;i<=n;++i)cin>>a[i];
        std::sort(a.begin()+1,a.end());
        for(int i=1;i<=n;++i)pre[i] = pre[i-1] + a[i];
        int l=0,r=n,mid;
        while(l<r){
            mid = (l + r + 1)/2;
            if(check(mid))l=mid;
            else r = mid-1;
        }
        cout<<l<<'\n';
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Solve();
    return 0;
}
