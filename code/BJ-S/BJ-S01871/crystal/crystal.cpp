#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,ans=1,t=1;
long long m,a[N],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        cnt+=(i-t)*(a[i]-a[i-1]);
        while(cnt>m && t<=i) cnt-=(a[i]-a[t++]);
        if(cnt<=m) ans=max(ans,i-t+1);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
