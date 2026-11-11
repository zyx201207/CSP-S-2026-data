#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    ll l=0,r=n;
    while(l<r){
        ll temp=min(a[l],a[r]);
        if(c[l]!=c[r]) ans+=temp;
        a[l]-=temp;
        a[r]-=temp;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans;
    return 0;
}
