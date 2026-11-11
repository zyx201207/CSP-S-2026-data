#include <bits/stdc++.h>
using namespace std;
long long n, a, l, r, ans = 0;
char c;
vector<long long> u;
vector<char> v;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a >> c;
        u.push_back(a);
        v.push_back(c);
    }
    l = 0;
    r = u.size();
    while(l <= r){
        if(v[l] == v[r]){
            if(u[l] > u[r]){
                u[l] -= u[r];
                r --;
            }else if(u[l] < u[r]){
                u[r] -= u[l];
                l ++;
            }else{
                l ++;
                r --;
            }
        }else{
            ans += min(u[l], u[r]);
            if(u[l] > u[r]){
                u[l] -= u[r];
                r --;
            }else if(u[l] < u[r]){
                u[r] -= u[l];
                l ++;
            }else{
                l ++;
                r --;
            }
        }
    }
    cout << ans;
    return 0;
}
