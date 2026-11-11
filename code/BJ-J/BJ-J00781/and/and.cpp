#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    long long n , m;
    cin >> n >> m;
    long long maxn = 0;
    vector<long long> v(n , 0);
    for(long long i = 0;i < n;i ++){
        cin >> v[i];
        maxn = max(maxn , v[i]);
    }
    long long pow_2 = 1;
    while(pow_2 < maxn){
        pow_2 *= 2;
        if(pow_2 > maxn){
            pow_2 /= 2;
            break;
        }
    }
    long long ans = 0;
    while(pow_2 >= 1){
        vector<long long> vec(0);
        long long all_1 = 0;
        for(long long i = 0;i < v.size();i ++){
            if(v[i] >= pow_2){
                all_1 ++;
                vec.push_back(v[i]);
            }
        }
        if(all_1 >= m){
            for(long long i = 0;i < vec.size();i ++){
                vec[i] -= pow_2;
            }
            v = vec;
            ans += pow_2;
        }
        pow_2 /= 2;
    }
    cout << ans;
    return 0;
}
// 5 3
// 31 3 1 15 7

