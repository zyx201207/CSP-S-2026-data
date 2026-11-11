#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll a[maxn],s[maxn],n,m,ans;
bool chk(int ans){
    for(int i=ans;i<=n;i++){
        if((a[i]*ans-(s[i]-s[i-ans]))<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    s[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        // cout<<l<<" "<<r<<endl;
        if(chk(mid)){
            ans=mid,l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;   
}