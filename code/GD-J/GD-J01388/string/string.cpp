#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,ans,a[maxn];
char c[maxn];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    while (l<r) {
        if (a[l]>=a[r]) {
            if (c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            r--;
            if (a[l]==0) l++;
        }
        else {
            if (c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            l++;
            if (a[r]==0) r--;
        }
    }
    cout<<ans;
    return 0;
}
/*
4
2 a
3 b
4 c
2 a

4
2 a
3 b
5 c
2 a

4
2 a
1 b
3 c
1 a

4
2 a
2 b
1 a
1 c

5
2 a
1 b
3 c
2 b
3 a
*/