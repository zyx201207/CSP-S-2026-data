#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int n, k;
    cin >> n >> n;
    while(n--)
    {
        cin >> k;
        cout << rand() % k << endl;
    }
    return 0;
}