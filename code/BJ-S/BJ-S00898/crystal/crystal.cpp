#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],c[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
    }
    int cnt=0,ans=1,tms=0,amt=c[1];
    for(int l=1,r=1;r<n&&l<n;){
        r++,tms++;
        cnt+=c[r-1]*tms;
        while(cnt>m){
            l++;
            tms--;
            cnt-=amt;
            amt-=c[l-1];
        }
        amt+=c[r];
        ans=max(ans,r-l+1);
        //cout<<l<<' '<<r<<' '<<cnt<<' '<<ans<<' '<<tms<<' '<<amt<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}