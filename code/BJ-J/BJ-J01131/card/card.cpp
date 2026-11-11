#include<bits/stdc++.h>
using namespace std;

//每过一个数就标记上这个数
//如果出现重复的就向前把前面的都变成0
//直到变到上一个同样的数
//最后统计时0不算在内

long long tong[500010];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(tong[a[i]] != 0) {
            for(int j = 0; j < i; j++) {
                tong[a[j]] = 0;
                if(tong[a[i]] == 0) {
                    break;
                }
            }
        }
        tong[a[i]]++;
    }

    for(auto i : tong) {
        if(tong[i] == 0) {
            continue;
        }
        else {
            cout << i << " ";
        }
    }
    return 0;
}
