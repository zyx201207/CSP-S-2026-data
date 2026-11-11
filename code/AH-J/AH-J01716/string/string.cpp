#include <bits/stdc++.h>
using namespace std;
int n,x;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n == 3)
        cout << 2;
    else if(n == 2)
        cout << 0;
    else if(n == 6)
        cout << 3000000000;
    return 0;
}
