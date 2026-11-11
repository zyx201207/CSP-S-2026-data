#include<iostream>
#include<algorithm>
constexpr int maxn=5e5+5;
int n;long long a[maxn],s,ans,m;
int main(){
    std::freopen("crystal.in","r",stdin);
    std::freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>m;
    for(int i=1;i<=n;++i) std::cin>>a[i];
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i]*(i-1)-s>m) break;
        s+=a[i];ans=i;
    }
    std::cout<<ans;
    return 0;
}