#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll ar[N];
int sum[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>ar[i];
    }
    sort(ar+1, ar+1+n);
    int ans=1;
    int l=1;
    for (int i=1; i<=n; i++){
        sum[i]=sum[i-1]+ar[i];
        if (i==1) continue;
        while (ar[i]*(i-l+1)-(sum[i]-sum[l-1])>m)
            l++;
        // cout<<l<<"\n";
        ans=max(ans, i-l+1);
    }
    cout<<ans;
    return 0;
}