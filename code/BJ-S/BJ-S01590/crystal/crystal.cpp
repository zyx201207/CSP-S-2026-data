#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=500005;
int n,p,ans;
long long m,a[MAXN],s[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        s[i]=s[i-1]+a[i];
        while(a[i]*(i-p)-s[i]+s[p]>m) p++;
        ans=max(ans,i-p);
    }
    cout << ans;
    return 0;
}