#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+2;
ll a[N],s[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;ll m;cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    int ans=0;ll sum=0;
    for(int i=2; i<=n; i++){
        sum+=(a[i]-a[i-1])*(i-1);
        int l=1,r=i,t=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(sum-((mid-1)*a[i]-s[mid-1])<=m) t=i-mid+1,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
