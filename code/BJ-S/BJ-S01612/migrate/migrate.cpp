#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(c<=6){
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                
            }
        }
    }
    if(c==0||c==11||c==12){
        int p=x[2]-x[1];
        if(d<p*2)cout<<0<<'\n';
        else cout<<max((long long)0,n-(d/p)*2+1)<<'\n';
    }
    if(c==13||c==14){
        int cnt=0,a[3];
        for(int i=1;i<=n;i++){
            if(x[i]-d<x[1]&&x[i]+d>x[n]){
                cnt++;
                if(cnt>=3){
                    cout<<0<<'\n';
                    return;
                }
                a[cnt]=i;
            }
        }
        if(cnt==2){
            int l=1,r=n+1;
            while(l<r){
                int mid=(l+r)/2;
                if(x[mid]<x[a[1]-1]+d)l=mid+1;
                else r=mid;
            }
            int ll=n-l+1;
            l=0,r=n;
            while(l<r){
                int mid=(l+r+1)/2;
                if(x[mid]>x[a[2]+1]-d)r=mid-1;
                else l=mid;
            }
            int rr=l;
            cout<<ll*rr<<'\n';
        }
        if(cnt==1){
            int l=1,r=n+1;
            while(l<r){
                int mid=(l+r)/2;
                if(x[mid]<x[a[1]-2]+d)l=mid+1;
                else r=mid;
            }
            int ll=n-l+1;
            l=0,r=n;
            while(l<r){
                int mid=(l+r+1)/2;
                if(x[mid]>x[a[1]+2]-d)r=mid-1;
                else l=mid;
            }
            int rr=l;
            cout<<ll*rr<<'\n';
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
