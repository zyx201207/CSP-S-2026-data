#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[500005],s[500005],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i,pos=i;
        while(l<=r){
            int mid=(l+r)/2;
            ll S=s[i]-s[mid-1];
            ll tar=a[i]*(ll)(i-mid+1);
            if(tar-S<=m){
                pos=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<"\n";
    return 0;
}