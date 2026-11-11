#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n;
long long m,a[N];
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=1,l=1;
    long long sum=0;
    for(int r=1;r<=n;r++){
        while(l < r && sum + 1ll*(r-l)*(a[r]-a[r-1]) > m){
            sum-=a[r-1]-a[l];
            l++;
        }
        if(sum + 1ll*(r-l)*(a[r]-a[r-1]) > m || l == r){
            sum=0;
        }else sum += 1ll*(r-l)*(a[r]-a[r-1]);
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);

    return 0;
}
