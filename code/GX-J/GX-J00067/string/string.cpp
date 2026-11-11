#include <bits/stdc++.h>
using namespace std;

struct s {
    long long a = 0;
    string s = "";
} arr[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n;
    cin >> n;
    long long minn = 1000000000000;
    long long l = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].a >> arr[i].s;

        l += arr[i].a;
        if(arr[i - 1].s == arr[i].s && i != 1) {
            arr[i].a += arr[i - 1].a;
            arr[i - 1].a = 0;
        }
    }

    s arr2[n + 1];
    for(int i = 1; i <= n; i++) {
        arr2[i] = arr[i];
    }

    long long l2 = (l + 1) / 2;
    for(int i = 1; i <= n; i++) {
        if(arr2[i].a == 0) {
            continue;
        }
        if(l2 >= arr2[i].a) {
            l2 -= arr2[i].a;

            for(int j = n; j >= 1; j--) {
                if(arr2[j].a == 0 || i == j) {
                    continue;
                }
                if(arr2[i].a <= arr2[j].a && arr2[i].s == arr2[j].s) {
                    arr2[j].a -= arr2[i].a;
                    arr2[i].a = 0;
                    break;
                }
                else if(arr2[i].a > arr2[j].a && arr2[i].s == arr2[j].s) {
                    arr2[i].a -= arr2[j].a;
                    arr2[j].a = 0;
                }
                else if(arr2[i].a <= arr2[j].a && arr2[i].s != arr2[j].s) {
                    ans += arr2[i].a;
                    //cout << arr[i].a << "....."<<endl;
                    arr2[j].a -= arr2[i].a;
                    arr2[i].a = 0;
                    break;
                }
                else if(arr2[i].a > arr2[j].a && arr2[i].s != arr2[j].s) {
                    ans += arr[j].a;
                    //cout << arr[j].a << "///"<< endl;
                    arr2[i].a -= arr2[j].a;
                    arr2[j].a = 0;
                }
            }
        }
        else {
            ans += l - arr2[i].a;
            break;
            //cout <<"???"<< endl;
        }
    }

    minn = ans;

    ans = 0;
    for(int i = 1; i <= n; i++) {
        arr2[i] = arr[i];
    }
    l2 = (l + 1) / 2;
    for(int i = n; i >= 1; i--) {
        if(arr2[i].a == 0) {
            continue;
        }
        if(l2 >= arr2[i].a) {
            l2 -= arr2[i].a;

            for(int j = 1; j <= n; j++) {
                if(arr2[j].a == 0 || i == j) {
                    continue;
                }
                if(arr2[i].a <= arr2[j].a && arr2[i].s == arr2[j].s) {
                    arr2[j].a -= arr2[i].a;
                    arr2[i].a = 0;
                    break;
                }
                else if(arr2[i].a > arr2[j].a && arr2[i].s == arr2[j].s) {
                    arr2[i].a -= arr2[j].a;
                    arr2[j].a = 0;
                }
                else if(arr2[i].a <= arr2[j].a && arr2[i].s != arr2[j].s) {
                    ans += arr2[i].a;
                    //cout << arr[i].a << "....."<<endl;
                    arr2[j].a -= arr2[i].a;
                    arr2[i].a = 0;
                    break;
                }
                else if(arr2[i].a > arr2[j].a && arr2[i].s != arr2[j].s) {
                    ans += arr[j].a;
                    //cout << arr[j].a << "///"<< endl;
                    arr2[i].a -= arr2[j].a;
                    arr2[j].a = 0;
                }
            }
        }
        else {
            ans += l - arr2[i].a;
            break;
            //cout <<"???"<< endl;
        }
    }

    minn = min(ans, minn);

    cout << minn << endl;

    return 0;
}
