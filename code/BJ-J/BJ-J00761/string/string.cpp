#include <bits/stdc++.h>
const int MAXN=2e5+5;
using namespace std;
int n,a[MAXN];
char c[MAXN];
long long sum,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
    }
    if (n==1){
        cout << 0;
        return 0;
    }
    if (n==2){
        if (c[1]==c[2]){
            cout << 0;
        }
        else{
            cout << min(a[1],a[2]);
        }
        return 0;
    }
    for (int i=1,j=n;i<=n/2;i++,j--){
        if (c[i]!=c[j]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
