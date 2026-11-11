#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        long long mn=1e18;
        for(int i=1;i+mid-1<=n;i++){
            int j=i+mid-1;
            long long cur=(mid-1)*a[j]-(sum[j-1]-sum[i-1]);
            mn=min(mn,cur);
        }
        if(mn<=m){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
