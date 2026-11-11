#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
int n,ans;
ll m,a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1,j=1;i<=n;i++){
        while(a[i]*(i-j+1)>s[i]-s[j-1]+m&&j<i) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
//CSP-S 2026 rp++