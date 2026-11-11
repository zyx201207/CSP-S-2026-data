#include <iostream>
#define MAXN 200005
#define int long long
using namespace std;
int n;
int a[MAXN];
char c[MAXN];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
    }

    int ans = 0;
    int i=1, j=n;
    while(i < j) {
        int mina = min(a[i], a[j]);
        a[i] -= mina;
        a[j] -= mina;
        if(c[i] != c[j]) {
            ans += mina;
        }
        if(a[i] == 0) {
            i++;
        }
        if(a[j] == 0) {
            j--;
        }
    }
    cout<<ans;
    return 0;
}