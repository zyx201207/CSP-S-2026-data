#include <iostream>
using namespace std;

typedef long long LL;

LL n;
LL a[200010];
char c[200010];
LL ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    LL l=1;
    LL r=n;
    LL dl=0;
    LL dr=0;
    while(l<r){
        LL tmp=min(a[r]-dr,a[l]-dl);
        if(c[l]!=c[r]){
            ans+=tmp;
        }
        dl+=tmp;
        dr+=tmp;
        if(dl==a[l]){
            l++;
            dl=0;
        }
        if(dr==a[r]){
            r--;
            dr=0;
        }
    }
    cout<<ans;
    return 0;
}