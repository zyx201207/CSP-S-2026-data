#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500005]={}, ans[300005]={};

    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        ans[a[i]]++;
    }
    for (int i=1; i<=m; i++)
    {
        if (ans[i]){
            cout << n<<" ";}
    }
    return 0;
}
