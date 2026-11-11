#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]) ans+=min(a[l],a[r]);
        if(a[r]==a[l]) l++,r--;
        else if(a[r]<a[l]) a[l]-=a[r],a[r--]=0;
        else a[r]-=a[l],a[l++]=0;
    }
    cout << ans;
    return 0;
}
