#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long m;
long long a[500010];

int main(){
    freopen("crystal.in" , "r", stdin);
    freopen("crystal.out" , "w", stdout);

    scanf("%lld %lld", &n, &m);

    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a+1, a+n+1);

    for(int i=1; i<=n; i++){
        bool flag = false;
        long long cnt = 0;
        long long sum = 0;
        for(int j=i; j>=1; j--){
            cnt += (a[i]-a[j]);
            sum++;
            if(cnt > m){
                ans = max(ans, sum-1);
                flag = true;
                //cout << i << " " << j << " " << sum-1 << " " << ans << " " << cnt << endl;
                break;
            }
        }
        if(flag == false){
            ans = max(ans, sum);
        }
    }

    printf("%lld", ans);
    return 0;
}

