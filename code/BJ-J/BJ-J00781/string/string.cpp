#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    long long n;
    cin >> n;
    vector<long long> v(n , 0);
    vector<char> c(n , 0);
    for(long long i = 0;i < n;i ++){
        cin >> v[i] >> c[i];
    }
    long long left = 0 , right = n - 1;
    long long ans = 0;
    while(true){
        if(left == right || left > right){
            break;
        }
        if(v[left] > v[right]){
            if(c[left] != c[right]){
                ans += v[right];
            }
            v[left] -= v[right];
            v[right] = 0;
            right --;
        }
        if(v[left] < v[right]){
            if(c[left] != c[right]){
                ans += v[left];
            }
            v[right] -= v[left];
            v[left] = 0;
            left ++;
        }
        if(v[left] == v[right]){
            if(c[left] != c[right]){
                ans += v[left];
            }
            left ++;
            right --;
        }
    }
    cout << ans;
    return 0;
}
