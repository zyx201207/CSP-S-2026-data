#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005];
ll s[500005];
bool check(int l,int r){
    return (r-l)*a[r]-(s[r-1]-s[l-1])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=1,ptr=1;
    for(int i=1;i<=n;i++){
        while(ptr<n&&check(i,ptr+1)) ptr++;
        ans=max(ans,ptr-i+1);
    }
    printf("%d",ans);
    return 0;
}
//AC!!!!! by 11?????=10?????