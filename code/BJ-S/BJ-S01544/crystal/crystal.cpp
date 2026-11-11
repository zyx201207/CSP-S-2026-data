#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pre[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,loc;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
                loc=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-loc+1);
    }
    cout<<ans;
    return 0;
}
