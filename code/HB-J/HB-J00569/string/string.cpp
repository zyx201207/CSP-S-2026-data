#include <bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for (long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1ll,r=n;
    long long ans=0ll;
    while (l<r){
        long long mn=min(a[l],a[r]);
        if (c[l]!=c[r]){
            ans+=mn;
        }
        a[l]-=mn;
        a[r]-=mn;
        if (a[l]==0)l++;
        if (a[r]==0)r--;
    }
    printf("%lld",ans);
    return 0;
}
//Desktop/HB-J00569/string/string.cpp >hEllo

