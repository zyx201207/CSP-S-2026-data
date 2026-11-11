#include <bits/stdc++.h>
using namespace std;

int arr[200000+10];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a;
    cin >> n >> a;
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = arr[n-1];
    for (int i = n-2 ; i >= n-1-a ; i--){
        ans &= arr[i];
    }
    cout << ans;
    return 0;
}
