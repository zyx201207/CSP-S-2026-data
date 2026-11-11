#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n, m, a[N], c[N], s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=a[n]-a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+c[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1, r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(s[i]-s[mid-1]-(i-mid+1)*c[i]<=m)r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout << ans;
    return 0;
}
