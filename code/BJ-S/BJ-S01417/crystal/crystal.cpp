#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],m;
bool check(int idx){
    long long now=0;
    for(int i=1;i<idx;i++){
        now+=a[idx]-a[i];
    }
    if(now<=m) return true;
    else return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    // putchar('!');
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    // putchar('!');
    sort(a+1,a+n+1);
    // putchar('!');
    int L=1,R=n,ans=0;
    while(L<R){
        int mid=(L+R)/2;
        if(check(mid)){
            ans=mid;
            L=mid+1;
        }
        else R=mid;
    }

    printf("%d\n",ans);
    return 0;
}