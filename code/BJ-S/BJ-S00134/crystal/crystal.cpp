#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
long long n,m,a[N],sum[N],ans;
unordered_map<long long,long long>ma;
unordered_map<long long,long long>t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i<=n;i++){
        sum[i] = sum[i - 1] + a[i];
        if(ma[a[i]] == 0){
            ma[a[i]] = i;
        }
    }
    for(int i = 1;i<=n;i++){
        long long l = 1,r = ma[a[i]] - 1,res = 0,s = ma[a[i]] - 1;
        while(l <= r){
            long long mid = (l + r) >> 1;
            long long x = a[i] * (s - mid + 1) - (sum[s] - sum[mid - 1]);
            if(x <= m){
                res = s - mid + 1;
                r = mid - 1;
            }else l = mid + 1;
        }
        //cout<<i<<" "<<res<<'\n';
        ans = max(ans,res + t[a[i]]);
    }
    cout<<ans;
    return 0;
}