#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],f[200005],cnt,ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        f[i]=f[i-1]+a[i];
        cnt+=a[i];
    }
    long long l=1,r=cnt,p=1,q=n;
    while(l<=r){
        if(c[p]!=c[q]){
            ans+=min(f[p]+1-l,r-f[q-1]);
        }
        //cout<<l<<' '<<r<<' '<<p<<' '<<q<<' '<<ans<<"\n";
        int t=min(f[p]+1-l,r-f[q-1]);
        l+=t;
        r-=t;
        if(l>f[p])p++;
        if(r<=f[q-1])q--;
    }
    cout<<ans;
    return 0;
}
