#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin >> n >> m;

    if (n == 0 || m == 0) {
        cout << "0" << endl;
        return 0;
    }

    int* an = new int[n];
    for (int i = 0;i < n;i++) {
        cin >> an[i];
    }
    sort(an,an + n);

    int end = 0;
    for (int i = 0;i < n;i++) {
        int sum = 0,a = 0;
        for (int j = i; j >= 0;j--) {
            sum += an[i] - an[j];
            if (sum > m) {
                break;
            }
            a++;
        }
        end = max(end,a);
    }
    cout << end << endl;
}