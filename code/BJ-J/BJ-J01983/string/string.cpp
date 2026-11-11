#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
    long long l=1,r=n,x1=0,ans=0;
    while(l<r) {
        x1=a[l]-a[r];
        if(c[l]!=c[r]) ans+=min(a[l],a[r]);
        a[l]-=min(a[l],a[r]);
        a[r]-=min(a[l],a[r]);
        if(x1>0) r--;
        else if(x1<0) l++;
        else { l++; r--; }
    }
    cout << ans;
    return 0;
}
