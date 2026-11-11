#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cf[500005],ans=1,cnt,jl=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    while(r<n){
        if(cnt+(r-l+1)*(a[r+1]-a[r])<=m){
            r++;
            jl++;
            cnt+=(r-l)*(a[r]-a[r-1]);
            ans=max(ans,jl);
        }
        else{
            jl--;
            cnt-=a[r]-a[l];
            l++;
            if(l>r){
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}
