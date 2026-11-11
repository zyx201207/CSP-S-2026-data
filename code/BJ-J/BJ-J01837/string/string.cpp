#include<bits/stdc++.h>
using namespace std;
struct node {
    int a;
    char b;
}arr[200005];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }
    int l = 1, r = n;
    long long ans = 0;
    while(l < r) {
        if(arr[l].b == arr[r].b) {
            if(arr[l].a > arr[r].a) {
                arr[l].a -= arr[r].a;
                r--;
            } else if(arr[l].a < arr[r].a) {
                arr[r].a -= arr[l].a;
                l++;
            } else {
                l++;
                r--;
            }
        } else {
            if(arr[l].a > arr[r].a) {
                ans += arr[r].a;
                arr[l].a -= arr[r].a;
                r--;
            } else if(arr[l].a < arr[r].a) {
                ans += arr[l].a;
                arr[r].a -= arr[l].a;
                l++;
            } else {
                ans += arr[l].a;
                l++;
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}