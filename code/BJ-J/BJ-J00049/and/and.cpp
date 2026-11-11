#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int M = pow(2,31)-1;
int n,m;
long long a[N];
long long ans=0;
void dfs(int k,int v,long long sum) {
    if ((m-v)>(n-k)) return;
    if(sum<ans) return;
    if (k==n) {
        if (sum!=M) ans = max(ans,sum);
        return;
    }
    dfs(k+1,v,sum);
    if (v<m) {
        dfs(k+1,v+1,sum&a[k]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n>>m;
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }
    dfs(0,0,M);
    cout << ans << endl;
    return 0;
}
