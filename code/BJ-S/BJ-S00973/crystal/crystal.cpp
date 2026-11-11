#include <bits/stdc++.h>
using namespace std;
//test:AC AC AC AC
const int N = 5e5+7;
int n,ans;
long long int m,a[N],f;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    a[0] = a[1];
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        f+=(a[i]-a[i-1])*cnt;
        cnt++;
        while(f>m){
            f-=a[i]-a[i-cnt+1];
            cnt--;
        }
        ans = max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}