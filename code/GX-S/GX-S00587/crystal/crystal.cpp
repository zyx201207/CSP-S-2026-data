#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n, m, ans, maxn=1;
int a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n>> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];

    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++){
        ans=1;
        int sum=0;
        if (m==0) break;
        for (int j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if (sum>m) break;
            ans++;
        }
        maxn=max(ans,maxn);
    }

    cout << maxn;
    return 0;
}
