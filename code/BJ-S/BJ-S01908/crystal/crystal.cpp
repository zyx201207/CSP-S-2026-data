#include<bits/stdc++.h>
using namespace std;
int n;
long long m,cnt;
long long a[500005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int L=1;
    for(int R=1;R<=n;R++){
        while(L<R&&cnt+(long long)(R-L)*(a[R]-a[R-1])>m){
            cnt-=a[R-1]-a[L++];
        }
        cnt+=(long long)(R-L)*(a[R]-a[R-1]);
        ans=max(ans,R-L+1);
    }
    printf("%d",ans);
    return 0;
}
