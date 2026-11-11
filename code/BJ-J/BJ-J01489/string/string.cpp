#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[30];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    string s;
    for(long long i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        string t;
        for(long long j=1;j<=a[i];j++){
            t=t+c[i];
        }
        s+=t;
    }
    long long len=s.size();
    long long ans=0;
    for(long long i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])ans++;
    }
    printf("%lld",ans);
    return 0;
}
