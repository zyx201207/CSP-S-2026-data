#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],sum[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,res=i;
        while(l<=r){
            long long mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m){
                r=mid-1;
                res=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
