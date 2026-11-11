#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];

int main()
{
    freopen("travel.in","u","stdin");
    freopen("travel.out","w","stdout");
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    cout << n*a[1]/2;
    return 0;
}
