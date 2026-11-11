#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[500005],s[500005];
const int inf=500005;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int fil=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i,ans=inf;
        while(l<=r){
            int mid=(l+r)/2;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        fil=max(fil,i-ans+1);
    }
    cout<<fil;
    return 0;
}
