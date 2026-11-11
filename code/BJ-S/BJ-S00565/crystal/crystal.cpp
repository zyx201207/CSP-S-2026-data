#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],b[N],c[N],d[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1,less<int>());
    for(int i=1;i<n;++i){
        b[i]=a[i+1]-a[i];
    }
    for(int i=n-1;i>=1;--i){
        c[i]=b[i]+c[i+1];
        //cout<<b[i]<<' '<<c[i-1]<<endl;
    }
    for(int i=n-1;i>=1;--i){
        d[i]=c[i]+d[i+1];
    }
    for(int i=2;i<=n;++i){
        int l=1,r=i-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            int p=d[mid]-d[i]-(a[n]-a[i])*(i-mid);
            if(p>m) l=mid+1;
            else r=mid-1;
        }
        //cout<<mid<<endl;
        ans=max(ans,i-l+1);
        /*
            int p=0;
        for(int j=i-1;j>=1;--j){
            p=d[j]-d[i]-(a[n]-a[i])*(i-j);
            cout<<i<<' '<<j<<' '<<p<<endl;
            if(p>m){
                ans=max(ans,i-j);
                break;
            }
            if(j==1){
                ans=max(ans,i-j+1);
                break;
            }else{
                continue;
            }
        }
        */
    }
    cout<<ans<<endl;
    return 0;
}
