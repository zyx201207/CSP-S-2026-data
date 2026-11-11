#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
ll a[2000005];
int pre[2000005],suf[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int n;ll d,ans=0;cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],pre[i]=suf[i]=0;
        if(c==11||c==12){
            if(n==1) cout<<"0\n";
            else{
                ll k=a[2]-a[1];
                int cnt=d/k;
                if(cnt==1||cnt==0) cout<<"0\n";
                else cout<<max(n-(2*cnt)+1,0)<<'\n';
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            int j=lower_bound(a+1,a+i,a[i]-d)-a;
            if(j==i) continue;
            int k=lower_bound(a+1,a+j+1,a[j+1]-d)-a;
            pre[i]=i-j;
            if(k==j) pre[i]+=pre[j];
        }
        for(int i=n;i;i--){
            int j=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
            if(j==i) continue;
            int k=upper_bound(a+j-1,a+n+1,a[j-1]+d)-a-1;
            suf[i]=j-i;
            if(k==j) suf[i]+=suf[j];
        }
        for(int i=1;i<=n;i++) suf[i]+=suf[i-1];
        for(int i=1;i<=n;i++){
            int j=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
            if(j<=i+1) continue;
            int k1=upper_bound(a+j-1,a+n+1,a[j-1]+d)-a-1,k2=upper_bound(a+j,a+n+1,a[j]+d)-a-1;
            int l=upper_bound(a+j-2,a+n+1,a[j-2]+d)-a-1;
            if(k2==j) continue;
            ans+=k1-l;
            ans+=1ll*pre[i]*(suf[k1]-suf[l]+k1-l);
            // cout<<i<<' '<<j<<' '<<k1<<' '<<k2<<' '<<l<<' '<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }
}
/*10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/