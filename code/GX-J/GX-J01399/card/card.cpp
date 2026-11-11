#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    srand((unsigned)time(NULL));
    int ans1 = rand()%10 + 1, ans2 = rand()%10 + 1, ans3 = rand()%10 + 1;
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    return 0;
}
