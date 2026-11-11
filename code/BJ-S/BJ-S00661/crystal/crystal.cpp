#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int l=1,r=1;r<=n;r++){
        while(l<=r&&s[r]-s[l-1]+m<(r-l+1)*a[r]){
            l++;
        }
        if(s[r]-s[l-1]+m>=(r-l+1)*a[r]){
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans;
    return 0;
}
