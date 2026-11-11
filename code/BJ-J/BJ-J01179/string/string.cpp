#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans = 0,len;int n;
const int N = 2e5+5;
int a[N];ll lp[N],rp[N+3],rlp[N+2],rrp[N+1];char c[N],cr[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){scanf("%d %c",&a[i],&c[i]);cr[n+1-i]=c[i],len+=a[i],rp[i]=rp[i-1]+a[i],lp[i]=rp[i]-a[i]+1;}
    for(int i = 1;i<=n;i++)rlp[i]=len-rp[n-i+1]+1,rrp[i]=len-lp[n-i+1]+1;
    int l = 1,r=1;
    while(l<=n&&r<=n){
        while(rrp[r]<rp[l]){
            if(c[l]!=cr[r])ans += min(rrp[r],rp[l])-max(lp[l],rlp[r])+1;
            r++;
            if(r>n)break;
        }
        if(r>n)break;
        if(c[l]!=cr[r])ans += max(min(rrp[r],rp[l])-max(lp[l],rlp[r])+1,0ll);
        l++;
    }
    printf("%lld\n",ans>>1);
}