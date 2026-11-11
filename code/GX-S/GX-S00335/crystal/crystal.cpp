#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n;
ll m,ans=1,cnt;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(ll r=1,l=1;r<=n;r++){
        while((r-l+1)*a[r]-s[r]+s[l-1]>m&&l<r) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
