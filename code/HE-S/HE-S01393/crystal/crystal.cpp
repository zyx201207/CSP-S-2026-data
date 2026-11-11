#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

long long n,m;

vll arr;
vll pre;


bool check(int x,int i){
    ll cur = pre[i];
    cur -= pre[x] + (arr[i] - arr[x]) * x;

    return cur <= m;

}


int main()
{
    iostream::sync_with_stdio(false);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin >> n >> m;

    arr.resize(n);
    pre.resize(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    for(int i = 0; i<n-1; i++) pre[i+1] = pre[i] + (arr[i+1] - arr[i]) *(i+1);

    for(int i = 1;i<n;i++) if(pre[i] < 0 || pre[i] < pre[i-1]) return 1;

    int ans = -1;

    for(int i = 0;i<n;i++){
        int tgt = pre[i] - m;
        int l = 0,r = n,it = 0;
        while(l < r){
            int mid = l + ((r - l) >> 1);
            if(check(mid,i)) r = mid,it = mid;
            else l = mid + 1;
        }


        ans = max(ans,i - it + 1);

    }

    cout << ans << endl;

    return 0;
}
