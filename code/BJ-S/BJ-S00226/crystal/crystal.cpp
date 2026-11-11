#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    long long sum=m,ans=1;
    for(int i=2;i<=n;i++){
        long long t=(a[i]-a[i-1])*ans;
        if(sum<t)break;
        else sum-=t;
        ans++;
    }
    printf("%lld",ans);
    return 0;
}
