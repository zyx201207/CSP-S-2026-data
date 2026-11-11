#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,res=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(res!=-1) ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
//14:54