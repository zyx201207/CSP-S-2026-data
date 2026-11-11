#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500005];
ll pre[500005];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int l=1,r=0;
    bool flag=1;
    while(r<n){
        if(flag){
            r++;
            ll all=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
            if(all>m) flag=0;
            else ans=max(ans,r-l+1);
        }
        else{
            l++;
            ll all=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
            if(all<=m) flag=1;
        }
    }
    cout<<ans;
    return 0;
}
