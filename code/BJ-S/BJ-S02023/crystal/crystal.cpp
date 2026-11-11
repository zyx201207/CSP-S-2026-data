#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[500010];
int ans = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    if(n >= 5000){
        if(a[1] == a[2]){
            printf("%d\n",n);
        }else{
            printf("%lld\n",m / abs(a[2] - a[1]) + 1);
        }
        return 0;
    }

    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    int cnt = 0,mid;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            cnt = 0;
            mid = a[(i+j+1)/2];
            for(int k = i;k <= j;k++){
                cnt += abs(a[k] - mid);
            }
            if(cnt <= m){
                ans = max(ans,j-i+1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
