#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500050],b[500050],ans = 1;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    bool num = 1;
    for(int i = 1;i <= n;i ++){
        if(a[i] != i) {
            num = 0;
            break;
        }
    }
    if(num == 1){
        int i = 1;
        while(1){
            m -= i;
            if(m >= 0) i ++;
            else break;
        }
        cout << i;
        return 0;
    }
    num = 1;
    for(int i = 3;i <= n;i ++){
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
            num = 0;
            break;
        }
    }
    if(num == 1){
        int sum = 0,i = 1;
        while(1){
            m -= i;
            if(m >= 0){
                i += a[2] - a[1];
                sum++;
            }
            else break;
        }
        cout << sum;
        return 0;
    }
    for(int i = 1;i <= n;i ++) b[i] = a[i + 1] - a[i];
    for(int i = n / 2;i >= 1;i --){
        m -= b[i];
        b[i - 1] += a[n / 2 + 1] - a[i];
        if(m >= 0) ans ++;
        else{
            cout << ans;
            return 0;
        }
    }
    for(int i = n / 2 + 1;i <= n;i ++){
        m -= b[i] * i;
        if(m >= 0) ans ++;
        else{
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
