#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],man;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(i!=n && a[i]==a[i+1]) continue;
        long long t=m,js=1;
        for(int j=i-1;j>=1;j--){
            if(t>=a[i]-a[j]){
                t-=a[i]-a[j],js++;
            }
            else break;
        }
        if(js>man) man=js;
    }
    printf("%lld\n",man);
    return 0;
}
