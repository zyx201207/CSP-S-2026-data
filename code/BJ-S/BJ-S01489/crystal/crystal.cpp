#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];

int ans=-1;
int check(int x){
    int tot=m,res=0;
    for(int i=x;i>=1;i--){
        if(a[x]-a[i]<=tot){
            tot-=(a[x]-a[i]);
            res++;
        }else break;
    }
    return res;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        int res=check(mid);
        if(res>ans){
            ans=res;
            l=mid;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
