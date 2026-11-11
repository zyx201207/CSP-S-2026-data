#include<bits/stdc++.h>

#define int long long

const int N=500005;

int n,m;
int a[N];
int ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    std::cin>>n>>m;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::sort(a+1,a+n+1);
    int l=1,cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=a[i];
        while((i-l+1)*a[i]-cnt>m){
            cnt-=a[l];
            ++l;
        }
        ans=std::max(ans,i-l+1);
    }
    std::cout<<ans<<'\n';

    return 0;
}
