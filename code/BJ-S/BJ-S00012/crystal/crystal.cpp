#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=500005;
int n,m,sum,ans,a[N];
multiset<int> s;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int l=1,r=0;l<=n;l++){
        if(l!=1){
            s.erase(s.find(a[l-1]));
            sum-=a[l-1];
        }
        while(r<n&&(s.empty()||max(*prev(s.end()),a[r+1])*(r-l+2)-(sum+a[r+1])<=m)){
            r++;
            s.insert(a[r]);
            sum+=a[r];
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}