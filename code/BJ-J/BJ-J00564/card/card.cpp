#include <iostream>

using namespace std;

const int N = 2e5+10;
int arr[N];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cout << i << ' ';
    return 0;
}
