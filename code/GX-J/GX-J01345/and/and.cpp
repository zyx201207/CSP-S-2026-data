#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],man;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && (a[i] & a[j]>man)) man=a[i] & a[j];
            }
        }
        printf("%lld\n",man);
    }
    return 0;
}
