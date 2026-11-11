#include<iostream>
#include<string>
using namespace std;
long long n, a[200005], x_l = 0, ans = 0;
char c[200005];
char qushu(long long p){
    long long i = 1;
    while(p > a[i] && i <= n) i++;
    return c[i];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        a[i] += x_l;
        x_l = a[i];
    }
    for(long long i = 1;i <= x_l / 2;i++){
        if(qushu(i) != qushu(x_l-i+1)) ans++;
    }
    cout << ans << endl;
    return 0;
}
