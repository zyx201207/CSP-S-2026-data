#include <iostream>
#include <cmath>
using namespace std;

const int N = 2e5 + 5;

long long a[N];
char c[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i]>>c[i];

    long long cnt = 0;
    for (int i=0, j=n-1; i<j;) {
        //if (c[i] != c[j]) {
            long long minn = min(a[i], a[j]);
            if  (c[i] != c[j]) cnt += minn;
            a[i] -= minn, a[j] -= minn;
            if (a[i] <= 0) i++;
            if (a[j] <= 0) j--;
        //}
    }
    cout<<cnt<<endl;
    return 0;
}
//   BJ-J00178/string/string.cpp
