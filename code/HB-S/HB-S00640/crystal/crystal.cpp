#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long int n, m;
    long long int arr[500000];
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long int ans = 1;
    long long int count = 0;
    long long int r = n-1;

    for(int i = n-2; i >= 0; i--){
        count += arr[r] - arr[i];
        while(count > m){
            count -= (arr[r] - arr[r-1]) * (r-i);
            r--;
        }
        ans = max(ans, r-i+1);
    }
    
    cout << ans << endl;
    return 0;
}