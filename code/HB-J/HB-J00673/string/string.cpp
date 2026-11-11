#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("string.in", "r",stdin);
    freopen("string.out", "w",stdout);
    long long int n;
    long long int arr[200000];
    char c[200000];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i] >> c[i];
    }
    
    long long int l = 0, r = n-1, ans = 0;
    while(l < r){
        if(c[l] != c[r]){
            ans += min(arr[l], arr[r]);
        }
        long long int a = min(arr[l], arr[r]);
        arr[l] -= a;
        arr[r] -= a;
        if(arr[l] == 0) l++;
        if(arr[r] == 0) r--;
    }
    cout << ans << endl;
    return 0;
}