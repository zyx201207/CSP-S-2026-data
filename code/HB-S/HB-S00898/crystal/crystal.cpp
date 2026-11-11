#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=1;
int a[N];
int qsum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)qsum[i]=qsum[i-1]+a[i];
    for(int i=2;i<=n;i++){
        int l=1,r=i,mid,sum=0;
        while(l<=r){
            sum=0;
            mid=(l+r)>>1;
            sum=a[i]*(i-mid)-(qsum[i-1]-qsum[mid-1]);
            if(sum==m){
                ans=max(ans,i-mid+1);
                break;
            }else if(sum<m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}