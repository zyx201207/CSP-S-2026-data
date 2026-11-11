#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],s[N];
inline bool chk(int l,int r){
    int len=r-l+1;
    int sum=s[r]-s[l-1];
    return (sum+m)/len>=a[r];
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        if(i<n&&a[i]==a[i+1]) continue;
        int l=1,r=i,mid,id=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(chk(mid,i)) id=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-id+1);
    }
    cout<<ans;
}