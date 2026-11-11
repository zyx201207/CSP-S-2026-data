#include<bits/stdc++.h>
using namespace std;
long long a[200000+5];
char c[200000+5];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=1,r,ans=0;
    scanf("%lld",&n);
    r=n;
    for(long long i=1;i<=n;i++) scanf("%lld %c",&a[i],&c[i]);
    while(l<=r){
        if(a[l]==a[r]){
            if(c[l]!=c[r]) ans+=a[l];
            l++,r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l],l++;
        }
        else if(a[l]>a[r]){
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r],r--;
        }
    }
    printf("%lld",ans);
    return 0;
}