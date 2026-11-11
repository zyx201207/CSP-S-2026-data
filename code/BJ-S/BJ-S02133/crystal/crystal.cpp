#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
template <class TT>
using vc=vector<TT>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vc<long long> a(n+1), s(n+1);
    for(long long i=1;i <= n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end());
    for(long long i=1;i <= n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long ans=0;
    for(long long i=1;i <= n;i++){
        long long l=1, r=i, res=-1;
        while(l <= r){
            long long mid=(l+r)/2;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1]) <= m){
                r=mid-1;
                res=mid;
            }
            else l=mid+1;
        }
        ans=max(ans, i-res+1);
    }
    cout << ans;
}