#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
int a[500005];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld %lld",&n,&m);
    bool featA=true;
    int featB=INT_MIN;
    scanf("%d",&a[0]);
    scanf("%d",&a[1]);
    if ((a[0]!=1)||(a[1]!=2)) featA=false;
    featB=a[1]-a[0];
    for(int i = 2;i < n;i ++) {
        scanf("%d",&a[i]);
        if (a[i]!=(i+1)) featA=false;
        if ((a[i]-a[i-1]) != featB) featB=INT_MIN;
    }
    // Features solve.
    if (featA) {
        ll tm=m,FeatAi=1;
        for(FeatAi = 1;tm>=FeatAi&&FeatAi<n;FeatAi++) {
            tm-=FeatAi;
        }
        printf("%lld",FeatAi);
        return 0;
    }
    if (featB!=INT_MIN) {
        ll tm=m,FeatBi=0;
        for(FeatBi = featB;tm>=FeatBi&&FeatBi<n;FeatBi+=featB) {
            tm-=FeatBi;
        }
        printf("%lld",FeatBi/featB);
        return 0;
    }
    ll tot=0;
    for(int i = 0;i < n;i ++) {
            tot+=a[i];
    }
    printf("%d",tot/n);
    return 0;
}
//Oct31==Dec25?
