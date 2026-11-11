#include<bits/stdc++.h>
using namespace std;
long long ans;
long long n,a[200010];
char c[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    long long l=1,r=n;
    while(l<r) {
        long long minn=min(a[l],a[r]);
        if(c[l]!=c[r]) ans+=minn;
        a[l]-=minn;
        a[r]-=minn;
        if(a[l]<=0)l++;
        if(a[r]<=0)r--;
    }
    cout<<ans;
    return 0;
}
