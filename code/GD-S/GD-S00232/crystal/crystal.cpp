#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],n,s[N],m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        res=max(res,i-ans+1);
    }
    cout<<res;
}