#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cnt,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    if(n<=5000){
        for(int i=2;i<=n;i++){
            cnt=0;
            for(int j=1;j<=i-1;j++){
                cnt+=(a[i]-a[j]);
            }
            if(cnt<=m) ans=i;
            if(cnt>m){
                cout<<ans;
                return 0;
            }
        }
    }

    else {
        long long l=2,r=n,mid;
        while(l<=r){
            mid=(l+r)/2;
            cnt=0;
            for(int i=1;i<=mid-1;i++){
                cnt+=(a[mid]-a[i]);
            }
            if(cnt<=m) l=mid+1;
            if(cnt>=m) r=mid-1;
        }
        cout<<r;
    }
    return 0;
}
