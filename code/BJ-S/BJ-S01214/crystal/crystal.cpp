#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[500010];
int sum[500010];
int n,m,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+b[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if((i-mid+1)*b[i]-(sum[i]-sum[mid-1])<=m) r=mid-1;
            else l=mid+1;

        }
        ans=max(i-l+1,ans);
    }
    cout<<ans;
    return 0;
}
