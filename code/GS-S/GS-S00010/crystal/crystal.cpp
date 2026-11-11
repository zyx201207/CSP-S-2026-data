#include<bits/stdc++.h>
using namespace std;
int n,s=1;
long long m,a[500005],d[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
    for(int i=2,l,r,o;i<=n;i++)if(i==n||a[i]!=a[i+1]){
        l=0,r=i-1;
        while(l<=r){
            o=(l+r)>>1;
            if(a[i]*(i-o)-d[i-1]+d[o-1]<=m)r=o-1;
            else l=o+1;
        }s=max(s,i-l+1);
    }printf("%d",s);
    return 0;
}
