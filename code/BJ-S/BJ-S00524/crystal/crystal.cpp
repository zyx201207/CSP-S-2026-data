#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],l,r,mid,res;
ll sum[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        l=1;r=i;res=i;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)<=(sum[i]-sum[mid-1])+m) r=mid-1,res=mid;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
