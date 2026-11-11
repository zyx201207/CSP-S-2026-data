#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
// #define W(x) cerr<<#x<<':'<<x<<'\n'
using namespace std;
using ll=long long;
using db=long double;
using ull=unsigned long long;
const int N = 5e5+10;
const int M = 1e5+10;
const int MOD = 1e9+7;

int n,Ans;
ll m,a[N],sum[N];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1;i<=n;i++){
        int L = 1,R = i,res = -1;
        while(L<=R){
            int mid = (L+R)>>1;
            ll now = sum[i] - sum[mid-1];
            if(a[i]*(1ll*(i-mid+1))-now<=m){
                R = mid-1;
                res = mid;
            }else{
                L = mid+1;
            }
        }
        Ans = max(Ans,i-res+1);
    }
    cout << Ans << '\n';
    return 0;
}
/*
compile:
g++ -o A A.cpp -O2 -static -std=c++14

5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/