#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];int n,m,mx;
inline bool c(int x){
    int res=0;
    for(int i=1;i<=n;i++){
            //cout<<x<<' '<<a[i]<<' '<<(a[i]&x)<<endl;
        if((a[i]&x)==x)res++;
    }//cout<<res<<endl;
    if(res>=m)return 1;
    return 0;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(register int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
    sort(a+1,a+n+1,greater<int>());
    int l=1,r=n,ans;
    while(l<=r){
        int mid=(l+r)/2;
        //cout<<l<<' '<<r<<endl;
        if(c(a[mid]))r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<a[ans];
    return 0;
}
