#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,num = 0;
    cin >> n;
    char c;
    string p;
    for (int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        for (int j = 1;j <= a;j++) p += c;
    }
    for (int i = 0;i < p.size() / 2;i++)
    {
        if (p[i] != p[p.size() - i - 1]) num++;
    }
    cout << num;
    return 0;
}
