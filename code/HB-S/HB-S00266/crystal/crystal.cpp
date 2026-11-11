#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500500],sum[500500];
bool f[500500];
bool check(int x,int e){
    if(sum[x]-sum[e+1]-(a[n]-a[e])*1ll*(e-x+1)<=m) return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) if(a[i+1]!=a[i]) f[i]=true;
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[n]-a[i];
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(f[i]){
            int l=1,r=i,mid=(l+r)/2;
            int ans=i;
            while(l<=r){
                if(check(mid,i)){
                    r=mid-1;
                    ans=mid;
                }else{
                    l=mid+1;
                }
                mid=(l+r)/2;
            }
            maxn=max(maxn,i-ans+1);
        }
    }
    cout<<maxn;
    return 0;
}
