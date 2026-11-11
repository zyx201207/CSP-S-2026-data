#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    int cnt=0,res=1;
    for(int i=1;i<=n;i++){
        int l=0,r=i-1,ans=i-1;
        while(l<=r){
            int md=(l+r)/2;
            if(a[i]*(i-md)-(s[i]-s[md])<=m){
                ans=md;
                r=md-1;
            }
            else{
                l=md+1;
            }
        }
        res=max(res,i-ans);
    }
    cout<<res;
    return 0;
}
