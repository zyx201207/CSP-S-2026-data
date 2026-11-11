#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compp(int x, int y){
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n = 10, m = 0;

    cin >> n >> m;
    int a[200000];


    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, compp);

    int maxn = a[0];

    for (int i = 1; i < m; i++){
        maxn &= a[i];
    }
    cout << maxn;


    fclose(stdin);
    fclose(stdout);

    return 0;
}

