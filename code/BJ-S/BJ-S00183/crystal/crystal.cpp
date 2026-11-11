#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll a1[maxn],sum[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int in;
    ll im;
    cin>>in>>im;
    rep(i,1,in)scanf("%lld",a1+i);
    sort(a1+1,a1+in+1);
    int ans=0,p=1;
    rep(i,1,in)sum[i]=sum[i-1]+a1[i];
    rep(i,1,in){
        while(p<i&&a1[i]*(i-p+1)-(sum[i]-sum[p-1])>im)p++;
        ans=max(ans,i-p+1);
    }
    cout<<ans<<endl;
    return 0;
}