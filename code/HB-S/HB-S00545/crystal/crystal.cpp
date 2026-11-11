#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N],m;
ll s[N]; 
bool check(int l,int r){
    ll sum=1ll*(r-l+1)*a[r]-(s[r]-s[l-1]);
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=1;
    for(int i=2;i<=n;i++){ 
        int l=1,r=i-1,pos=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,i)) pos=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return  0;
}