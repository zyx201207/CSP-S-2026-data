#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
long long a[200005], n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << a[n / 2 + 1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
