#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
inline ll mymax(ll a,ll b) {
    return a>b?a:b;
}
void ReadNum(ll &x) {
    char c;x=0;
    do c = getchar();while (c < '0'||c > '9');
    do x = x * 10 + (c ^ '0'),c=getchar();while(c>='0'&&c<='9');
}
char cs[200005];
ll as[200005];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    //printf("Passed freopen");
    scanf("%d",&n);
    for(int i = 0;i <n;i ++) {
        ReadNum(as[i]);
        cs[i]=getchar();
    }
    //printf("Passed Input\n");
    ll ans=0;
    for(ll i = 0,j=n;i <= n,j>i;/*Solve it inside*/) {
        //printf("While {%d,%d}\n",i,j);
        //When at The Same.
        if (cs[i]==cs[j]) {
            //Clean up the bigger one
            if (as[i]>as[j]) as[i]-=as[j],as[j]=0,j--;
            else as[j]-=as[i],as[i]=0,i++;
        } else {
            //When It's diff.
            // Do Cleaning too.
            if (as[i]>as[j]) ans+=as[j],as[i]-=as[j],as[j]=0,j--;
            else ans+=as[i],as[j]-=as[i],as[i]=0,i++;
        }
        //Solve That There.(Maybe_Unuse);
        if (!as[i]) i++;
        if (!cs[j]) j--;
    }
    printf("%lld\n",ans);
    return 0;
}
