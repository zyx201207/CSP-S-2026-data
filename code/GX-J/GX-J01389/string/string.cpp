#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        int nx=min(a[l],a[r]);
        a[l]-=nx;
        a[r]-=nx;
        if(c[l]!=c[r]) ans+=nx;
        if(!a[l]) l++;
        if(!a[r]) r--;
    }
    cout<<ans;
    return 0;
}
