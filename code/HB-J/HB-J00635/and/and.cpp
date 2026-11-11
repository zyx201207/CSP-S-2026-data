#include<bits/stdc++.h>
using namespace std;
long long ans, ans1, ans2, ans3, ans4;
struct node{
    long long x, y;
};
node a[200010];
long long cnt;
bool cmp(node x, node y){
    if(x.y != y.y){
        return x.y > y.y;
    }else{
        return x.x > y.x;
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long mx = 0;
    for(long long i = 1; i <= n; i++){
        cin >> a[i].x;
        mx = max(mx, a[i].x);
        long long n1 = a[i].x;
        while(n1 > 0){
            cnt += n1 % 2;
            n1 /= 2;
        }
        a[i].y = cnt;
        cnt = 0;
    }
    if(k == 1){
        cout << mx;
        return 0;
    }
    long long gs = 0;
    for(long long i = 2; i <= n; i++){
        if(a[i].x == a[i - 1].x + 1){
            gs++;
        }
    }
    if(gs == n - 1){
        long long myans = 0;
        for(long long i = n; i >= n - k + 1; i--){
            if(i == n){
                myans = a[i].x;
            }else{
                myans &= a[i].x;
            }
        }
        cout << myans;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    for(long long i = 1; i <= k; i++){
        if(i == 1){
            ans = a[i].x;
        }else{
            ans &= a[i].x;
        }
    }
    for(long long i = 2; i <= k + 1; i++){
        if(i == 1){
            ans1 = a[i].x;
        }else{
            ans1 &= a[i].x;
        }
    }
    for(long long i = 3; i <= k + 2; i++){
        if(i == 1){
            ans2 = a[i].x;
        }else{
            ans2 &= a[i].x;
        }
    }
    for(long long i = 4; i <= k + 3; i++){
        if(i == 1){
            ans3 = a[i].x;
        }else{
            ans3 &= a[i].x;
        }
    }
    for(long long i = 5; i <= k + 4; i++){
        if(i == 1){
            ans4 = a[i].x;
        }else{
            ans4 &= a[i].x;
        }
    }
    cout << max({ans, ans1, ans2, ans3, ans4});
    return 0;
}
//12
