#include <bits/stdc++.h>
using namespace std;
const long long N=2*1e5+2;
string s;
long long n,a[N],sum[N],l=1,r,len,mn,tepan1;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(!tepan1&&i>=2&&c[i]!=c[i-1]){
            tepan1=1;
        }len+=a[i],sum[i]=sum[i-1]+a[i];
    }if(n==1||!tepan1){
        cout<<0;
        return 0;
    }r=len;
    while(l<r){
        long long p,q=n;
        for(long long i=1;i<=n;i++){
            if(l>=s[i-1]&&l<s[i]){
                p=i;
            }
        }for(long long i=n;i>=1;i--){
            if(r>=s[i-1]&&r<s[i]){
                q=i;
            }
        }if(c[q]!=c[p]){
            mn++;
        }l++,r--;
    }cout<<mn;
    return 0;
}
