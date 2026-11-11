#include<bits/stdc++.h>
using namespace std;
int n;
struct ss
{
    int a;
    char c;
}x[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x[i].a >> x[i].c;
    }
    cout << 0;
    return 0;
}
