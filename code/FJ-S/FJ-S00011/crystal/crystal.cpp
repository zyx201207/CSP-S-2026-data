#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n,m;
vector<int> a;
vector<int> sum;

bool check(int x){
    for(int i = x;i <= n;i++){
        int s = sum[i]-sum[i-x];
        int need = a[i]*x-s;

        if(need <= m) return true;
    }

    return false;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    a.resize(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());

    sum.resize(n+1,0);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i-1]+a[i];
    }

    int l = 0;
    int r = n;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}
