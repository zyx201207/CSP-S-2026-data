#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int c[500005];
int n,m;
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    c[i]=a[i]-a[i-1];
    c[1]=0;
    int l=1;
    int cnt=0;
    for(int r=1;r<=n;r++){
        cnt+=c[r]*(r-l);
        while(cnt>m){
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}