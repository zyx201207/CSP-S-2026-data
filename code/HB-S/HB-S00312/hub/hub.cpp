#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
typedef long long ll;
ll idx;
ll q;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> idx >> q;
    srand(time(0));
    while (q --) cout << rand() % rand() << '\n';
    return 0;
}