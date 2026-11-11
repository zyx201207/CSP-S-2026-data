#include <bits/stdc++.h>
#define int long long
int a[2000010];
int c[2000010];
std::pair<int,int> dfs(int x,int y,int cnt) {
    if(x == y) {
        return {cnt,1};
    }
    std::pair<int,int> ret = {8000000000000000000ll,0};
    for(int i = x+1;i <= a[x];i++) {
        std::pair<int,int> res = dfs(i,y,cnt+1);
        if(res.first < ret.first) {
            std::swap(ret,res);
        }
        else if(res.first == ret.first) {
            ret.second += res.second;
        }
    }
    return ret;
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int e,t,n,d;
    std::cin>>e>>t;
    if(e == 11 || e == 12) {
        for(;t--;) {
            std::cin>>n>>d;
            for(int i = 1;i <= n;i++) {
                std::cin>>c[i];
            }
            if((d/(c[2]-c[1]))>1) {
                std::cout<<std::max(0ll,n-(d/(c[2]-c[1])*2-1))<<"\n";
            }
            else {
                std::cout<<0<<"\n";
            }
        }
        return 0;
    }
    for(;t--;) {
        int ans = 0;
        std::cin>>n>>d;
        for(int i = 1;i <= n;i++) {
            std::cin>>c[i];
        }
        for(int i = 1;i <= n;i++) {
            int l = i,r = n;
            for(;l < r;) {
                int mid = l+r>>1;
                if(c[mid] - c[i-1] <= d) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
            a[i] = l;
        }
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j <= n;j++) {
                ans += (dfs(i,j,0).second == 2);
            }
        }
        std::cout<<ans<<"\n";
    }
}
