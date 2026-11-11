#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
LL n,a[N],len;
char c[N];
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    len/=2;
    LL ans=0;
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=a[i];j++){
            s1+=c[i];
            ans++;
            if(ans==len) break;
        }
        if(ans==len) break;
    }
    ans=0;
    for(LL i=n;i>=1;i--){
        for(LL j=1;j<=a[i];j++){
            s2+=c[i];
            ans++;
            if(ans==len) break;
        }
        if(ans==len) break;
    }
    LL cnt=0;
    for(LL i=0;i<len;i++){
        if(s1[i]!=s2[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
