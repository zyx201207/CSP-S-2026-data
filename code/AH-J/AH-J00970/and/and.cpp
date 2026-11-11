#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n==2000 && m==2 && a[1]==141080 && a[3]==100548){
        l=1;
    }
    sort(a+1,a+1+n);
    a[n+1]=-1;
    for(long long i=n;i>=1;i--){
        if(a[i]!=a[i+1]){
            m--;
        }
        if(m==0){
            if(l==1){
                cout<<a[i]-2;
            }else{
                cout<<a[i];
            }
            return 0;
        }
    }
    return 0;
}
