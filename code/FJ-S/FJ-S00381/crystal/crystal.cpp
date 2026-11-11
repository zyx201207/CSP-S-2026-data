#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=5e5+5;
i64 n,m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int l=1,r=1;l<=n;l++){
        r=max(r,l);
        while(r<n && s[r+1]-s[l-1]+m>=a[r+1]*(r-l+2))r++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
}