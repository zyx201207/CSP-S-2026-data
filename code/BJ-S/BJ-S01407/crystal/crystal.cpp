#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[1000010];
int main(){
    freopen("crystal4.in" , "r" , stdin);
    freopen("crystal4.out" , "w" , stdout);
    cin >> n >> m;
    long long sum = 0;
    for(long long i = 1;i <= n;i ++){
        cin >> a[i];
        sum += a[i];
    }
    sum += m;
    sum = sum / n;
    long long ans = 0;
    for(long long i = 1;i <= n;i ++){
        if(a[i] <= sum) ans ++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}