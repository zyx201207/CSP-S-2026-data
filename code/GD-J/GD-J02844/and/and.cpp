#include <iostream>
#include <algorithm>

using namespace std;


int n,m;
unsigned long long a[200009];
unsigned long long x;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    x = a[n];
    for (int i = n;i > n - m;i--)
    {
        x &= a[i];

    }
    cout << x;
    return 0;
}
/*
0010
1111
1100
1100

11111
00011
00001
01111
00111




00001
00010
00011
00100
00101
00110
00111

00001
00010
00101
01000

*/
