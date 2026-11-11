#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,s2=0;
long long a[200010];

bool cmp(long long x,long long y)
{
    return x>y;
}

void dfs(long long s,long long sum,long long ind)
{
    s2++;
    if (s2 >= 99990000) return;
    if (ind >= n || s >= m) {
        ans=max(ans,sum);
        return;
    }
    if (sum == 0) {
        dfs(s+1,a[ind],ind+1);
        dfs(s,0,ind+1);
        return;
    }
    dfs(s+1,sum&a[ind],ind+1);
    dfs(s,sum,ind+1);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n,cmp);
    if (m == 1) {
        cout << a[1];
        return 0;
    }
    dfs(0,0,1);
    cout <<ans;
    return 0;
}
