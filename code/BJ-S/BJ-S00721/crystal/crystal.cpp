#include<bits/stdc++.h>
using namespace std;
long long find(vector<long long> v , long long t){
    long long l = 0 , r = v.size() - 1;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(v[mid] > t){
            r = mid - 1;
        } else if(v[mid] < t){
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return l;
}
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    long long n , m;
    cin >> n >> m;
    vector<long long> v(n , 0);
    for(long long i = 0;i < n;i ++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    vector<long long> vec(n , 0);
    vec[0] = 0;
    vec[1] = v[1] - v[0];
    for(long long i = 2;i < n;i ++){
        vec[i] = vec[i - 1] + (v[i] - v[i - 1]) * i;
    }
    long long ans = 1;
    for(long long i = 1;i < n;i ++){
        long long t = find(vec , vec[i] - m);
        if(t == vec.size()){
            continue;
        }
        ans = max(ans , i - t + 1);
    }
    cout << ans;
    return 0;
}
