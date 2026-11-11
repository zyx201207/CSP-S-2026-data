#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=0;
    int l=1,r=0;
    int res=0;
    while(r<n){
        r++;
        cnt+=(r-l)*(a[r]-a[r-1]);
        while(l<r&&cnt>m) cnt-=a[r]-a[l],l++;
        res=max(res,r-l+1);
    }
    cout<<res;
    return 0;
}
