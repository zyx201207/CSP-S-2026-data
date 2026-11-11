#include<bits/stdc++.h>
using namespace std;
#define online
constexpr int maxn=501010;
long long a[maxn];
int main(){
    #ifdef online
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    long long m;cin>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l=1;
    long long cnt=0;
    int ans=0;
    for(int r=1;r<=n;r++){
        cnt+=(r-l)*(a[r]-a[r-1]);
        while(cnt>m){
            cnt-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}