#include<bits/stdc++.h>
#define int long long
int n,m;
int a[500005];
using namespace std;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    int ans=0;
    while(r<=n){
        if(m>=0){
            ans=max(ans,r-l+1);
            m-=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        else{
            m+=a[r]-a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
