#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l=1,r,mid,sum,ans;
bool f(int x){
    sum=0;
    for(long long i=mid;i<=n;i++){
        for(long long j=1;j<=i;j++){
            sum+=a[i]-a[j];
        }
        if(sum==m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    r=m;
    sort(a+1,a+n+1);
    while(l<=r){
        mid=(l+r)/2;
        if(f(mid)){
            l=mid+1;
            ans=max(ans,mid);
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
