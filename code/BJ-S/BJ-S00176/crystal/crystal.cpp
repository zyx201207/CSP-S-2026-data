#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum[N];

int bsearch(int l,int r,int id){
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[id]*mid-(sum[id]-sum[id-mid]) <= m){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

int main(){
    //freopen("crystal.in","w",stdout);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int mx=bsearch(1,i,i);
        ans=max(ans,mx);
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
