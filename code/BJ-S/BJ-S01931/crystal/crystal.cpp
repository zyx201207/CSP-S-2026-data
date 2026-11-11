#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[555555];
long long ans;
long long cnt;
long long i,j;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(i = n;i >= 1;i--){
        cnt = 0;
        for(j = 1;1;j++){
            cnt += a[i] - a[i - j];
            if(cnt > m || i - j == 0){
                ans = max(ans,j);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

