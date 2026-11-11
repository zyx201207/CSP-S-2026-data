#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[501010],ans;
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
    sort(a+1,a+1+n);
    int l=1,r=1,mm=0;
    while(l<=r&&r<=n){
        int lim=a[r],ch=a[r]-a[r-1];
        if(mm+(r-l)*ch<=m){
            mm+=(r-l)*ch;
            ans=max(ans,r-l+1);
            r++;
        }
        else{
            mm-=a[r-1]-a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
