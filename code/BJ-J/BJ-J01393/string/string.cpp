

#include <iostream>

using namespace std;

long long count[200009];
char sign[200009];
int n;

int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> count[i] >> sign[i];
        
    }
    int st = 1, ed = n;
    long long cost = 0;
    while (st < ed) {
        if (sign[st] != sign[ed]) {
            cost += min(count[st], count[ed]);
        }
        if (count[st] < count[ed]) {
             count[ed] -= count[st];
             st++;
        }else if (count[st] > count[ed]) {
            count[st] -= count[ed];
            ed--;
        }else{
            st++, ed--;
        }
    }
    cout << cost << endl;
    return 0;
}