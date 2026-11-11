#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int c, t, n;
ll d, x[2000005], ans;
ll dp[2000005], cnt[2000005],ss[2000005];
void Clear(){
    for (int i = 1; i <= n; ++ i) dp[i] = 0x3f3f3f3f3f3f3f3f, cnt[i] = 0;
}
void clears(){
    for(int i=0;i<=n;++i)ss[i]=0;
}
void calc(int s){
    dp[s] = 0, cnt[s] = 1;
    Clear();
    clears();
    for (int i = s+1; i <= n; ++ i) {
        if(x[i]-x[s]<=d){dp[i]=1,cnt[i]=1;ss[i]=i-s;continue;}
        if(x[i]-x[i-1]>d)break;
        int pos = lower_bound(x+s,x+i,x[i]-d)-x; dp[i]=dp[pos]+1;
        int por = upper_bound(dp+s,dp+i,dp[pos])-dp-1;
        cnt[i] = ss[por]-ss[pos-1]; if(cnt[i]==2)++ans; ss[i]=ss[i-1]+cnt[i];
    }
    for (int i = s-1; i; -- i) {
        if(x[s]-x[i]<=d){dp[i]=1,cnt[i]=1;ss[1]++;continue;}
        if(x[i+1]-x[i]>d)break;
        int L=i+1,R=s,pos=i;
        while(L<=R){
            int mid=L+R>>1;
            if(x[mid]-x[i]<=d)pos=mid,L=mid+1;
            else R=mid-1;
        }
        dp[i]=dp[pos]+1;
        L=i+1,R=s;int pol=i;
        while(L<=R){
            int mid=L+R>>1;
            if(dp[mid]<=dp[pos])pol=mid,R=mid-1;
            else L=mid+1;
        }
        cnt[i]=ss[pos]-ss[pol-1];if(cnt[i]==2)++ans;ss[i]=ss[i+1]+cnt[i];
    }
}
void solve(){
    ans=0;
    cin>>n>>d;for(int i=1;i<=n;++i)cin>>x[i];
    if(n==1){cout<<"0\n";return;}
    if(c<=10){
        for(int s=1;s<=n;++s)calc(s);
        cout<<ans<<'\n';return;
    }
    if(c<=12){
        ll tmp=d/(x[2]-x[1]);if(tmp<=1){cout<<"0\n";return;}
        ll ppp=tmp*2-1;
        if(ppp>=n){cout<<"0\n";return;}
        cout<<n-ppp<<'\n';return;
    }
    if(c<=14){
        int pos=0;
        for(int i=1;i<=n;++i){
            if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                pos=i;break;
            }
        }
        if(pos>1&&pos<n)
        for(int j=1;j<pos;++j){
            if(pos<=n-2&&x[pos+2]-x[j]<=d)break;
            if(x[pos+1]-x[j]<=d){
                int tmp=upper_bound(x+1,x+n+1,x[pos-1]+d)-x;
                ans+=(n-tmp+1);
            }else{
                int tmp=upper_bound(x+1,x+n+1,x[pos-2]+d)-x;
                int rr=upper_bound(x+1,x+n+1,x[pos-1]+d)-x;
                ans+=(rr-tmp);
            }
        }
        cout<<ans<<'\n';
        return;
    }
    cout<<"0\n";
}
int main() {
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    faster;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
//zap
