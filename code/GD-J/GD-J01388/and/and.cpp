#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,m,ans,a[maxn],cnt[35];
bool b[maxn];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        for (int j=30;j>=0;j--)
            if ((a[i]>>j)&1) cnt[j]++;
    }
    int pos=-1;
    for (int i=30;i>=0;i--)
        if (cnt[i]>=m) {pos=i; break;}
    if (pos==-1) {
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++)
        b[i]=true;
    for (int i=pos;i>=0;i--) {
        if (cnt[i]<m) continue;
        for (int j=1;j<=n;j++)
            if (!((a[j]>>i)&1) && b[j]) b[j]=false;
        int tot=0;
        for (int j=1;j<=n;j++)
            if (b[j]) tot++;
        if (tot<m) break;
        ans+=(1<<i);
    }
    cout<<ans;
    return 0;
}