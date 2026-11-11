#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
int n;
long long m,a[maxn],s[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    int ans=1,j=1;
    for(int i=1;i<=n;i++){
        while(j<=i && (s[i]-s[j-1]+m<a[i]*(i-j+1))) j++;
        ans=max(ans,i-j+1);
    }
    printf("%d\n",ans);
    return 0;
}
