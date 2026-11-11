#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define int long long
vector<int> v, s;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;cin>>n>>m;
    v.pb(0);
    for(int i = 1;i<=n;i++){
        int x;cin>>x;
        v.pb(x);
    }
    sort(v.begin()+1, v.end());
    int sum = 0;
    for(int i:v){
        sum+=i;
        s.pb(sum);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int L = 1, R=i;
        int len=0, cost=0;
        while(L<R){
            int mid = L+((R-L)>>1);
            len = i-mid+1;
            cost = len*v[i]-(s[i]-s[mid-1]);
            if(cost>m){
                L=mid+1;
            }else if(cost<=m){
                R=mid;
            }
        }
        len  = i-L+1;
        cost = len*v[i]-s[i]+s[R-1];
        ans = max(ans, len);
    }
    cout<<ans<<endl;
    return 0;
}
