#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum[N],ans=0;
ll calc(int idx){
    int le=1,ri=idx,res=0;
    while(le<=ri){
        int mid=(le+ri)/2;
        if(1ll*(idx-mid+1)*a[idx]-(sum[idx]-sum[mid-1])<=m){
            res=mid;
            ri=mid-1;
        }else{
            le=mid+1;
        }
    }
    return idx-res+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,calc(i));
    }
    cout <<ans<<"\n";
    return 0;
}
