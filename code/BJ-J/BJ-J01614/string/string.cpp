#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=2e5+5;
int a[N],n;
using ll=long long;
ll sum[N];
char c[N];
ll query(ll l,ll r,char ch){
    // cout<<"q: "<<l<<' '<<r<<' '<<ch<<'\n';
    int s=lower_bound(sum+1,sum+n+1,l)-sum;
    int t=lower_bound(sum+1,sum+n+1,r)-sum;
    // cout<<s<<' '<<t<<'\n';
    if(s==t){
        // if(c[s]==ch) cout<<"ret val: "<<0<<'\n';
        // else cout<<"ret val: "<<r-l+1<<'\n';
        if(c[s]==ch) return 0;
        else return r-l+1;
    }
    else{
        ll ret=0;
        if(c[s]!=ch){
            ret+=sum[s]-l+1;
            // cout<<"c[s]!=ch: +="<<sum[s]-l+1<<'\n';
        }
        if(c[t]!=ch){
            ret+=r-sum[t-1];
            // cout<<"c[t]!=ch: +="<<r-sum[t-1]<<'\n';
        }
        for(int i=s+1;i<t;i++){
            if(c[i]!=ch){
                ret+=a[i];
                // cout<<"i: "<<i<<"  "<<"+="<<a[i]<<'\n';
            }
        }
        // cout<<"ret val: "<<ret<<'\n';
        return ret;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0ll;
    if(sum[n]&1){
        ll mid=(sum[n]+1)>>1;
        int i=1;
        for(;i<=n&&sum[i]<mid;i++){
            ll l=sum[i-1]+1,r=sum[i];
            ans+=query(sum[n]-r+1,sum[n]-l+1,c[i]);
            // cout<<"ans test: "<<ans<<'\n';
        }
        ans+=query(mid,sum[n]-sum[i-1],c[i]);
        // cout<<"ans test: "<<ans<<'\n';
    }
    else{
        ll mid=sum[n]>>1;
        int i=1;
        for(;i<=n&&sum[i]<mid;i++){
            ll l=sum[i-1]+1,r=sum[i];
            ans+=query(sum[n]-r+1,sum[n]-l+1,c[i]);
            // cout<<"ans test: "<<ans<<'\n';
        }
        ans+=query(mid+1,sum[n]-sum[i-1],c[i]);
        // cout<<"ans test: "<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}