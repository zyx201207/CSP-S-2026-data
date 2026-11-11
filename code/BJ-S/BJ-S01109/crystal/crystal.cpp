#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
int a[N];
long long sum[N];
int ans=-1e9;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<=r){
            mid=(l+r)/2;
            int cnt=i-mid+1;
            if(((long long)a[i]*cnt*1ll-(sum[i]-sum[mid-1]))==m){
                ans=max(ans,i-mid+1);
                break;
            }
            if(((long long)a[i]*cnt*1ll-(sum[i]-sum[mid-1]))<m&&((long long)a[i]*(cnt+1)*1ll-(sum[i]-sum[mid-2]))>m){
                ans=max(ans,i-mid+1);
                break;
            }
            if(((long long)a[i]*cnt*1ll-(sum[i]-sum[mid-1]))<m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-mid+1);
    }
    cout<<ans;
    return 0;
}
