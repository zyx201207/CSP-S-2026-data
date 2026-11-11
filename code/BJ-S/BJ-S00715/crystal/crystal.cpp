#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            int sum=(i-mid+1)*a[i];
            if(sum-(b[i]-b[mid-1])<=m){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}
