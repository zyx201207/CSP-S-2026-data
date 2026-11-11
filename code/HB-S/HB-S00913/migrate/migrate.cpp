#include <iostream>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

vector<ll> islands_distance(2*1e6);

ull c, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--)
    {
        ull n, d;
        cin >> n >> d;
        ll start, last, current;
        cin >> start;
        last = start;
        for (int i = 1; i < n; i++)
        {
            cin >> current;
            islands_distance[i] = current - last;
            last = current;
        }
    }
    
    return 0;
}