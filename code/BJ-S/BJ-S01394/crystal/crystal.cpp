#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5 + 100;
int n;
ll m,a[N],f[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        f[i] = f[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int l = 1,r = i;
        while(l < r){
            int mid = (l + r) / 2;
            int sum = a[i] * (i - mid + 1) - (f[i] - f[mid - 1]);
            if(sum <= m)r = mid;
            else l = mid + 1;
        }
        ans = max(ans,i - l + 1);
    }
    printf("%d\n",ans);
    return 0;
}