#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N],pre[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans = 0;
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i++){
        int l = 1,r = i - 1,idx = i;
        while(l <= r){
            int mid = (l + r) / 2;
            if((i - mid) * a[i] - (pre[i - 1] - pre[mid - 1]) <= m){
                idx = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans,i - idx + 1);
    }
    printf("%d",ans);

    return 0;
}