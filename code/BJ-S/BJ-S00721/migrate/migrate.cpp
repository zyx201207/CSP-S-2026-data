#include<bits/stdc++.h>
using namespace std;
long long ans(vector<long long> v , long long n , long long m){
    long long anser = 0;
    for(long long i = 0;i < n - 3;i ++){
        if(v[i + 3] - v[i] <= m) continue;
        if(v[i + 3] - v[i + 1] <= m) anser ++;
    }
    return anser;
}
int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    long long c , T;
    cin >> c >> T;
    while(T --){
        long long n , m;
        cin >> n >> m;
        vector<long long> v(n , 0);
        for(long long i = 0;i < n;i ++){
            cin >> v[i];
        }
        cout << ans(v , n , m) << endl;
    }
}
