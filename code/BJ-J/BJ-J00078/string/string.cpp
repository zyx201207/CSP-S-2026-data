#include <bits/stdc++.h>
using namespace std;

long long n, j, ans;
struct aaa
{
    long long num;
    char c;
}a[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].num >> a[i].c;
        ans += a[i].num;
    }
    bool flag = 1;
    j = n;
    for(int i = 1;i <= n;i++)
    {
        if(a[i].c != a[j].c)
        {
            flag = 0;
            break;
        }
        j--;
    }
    if(flag){cout << 0;}
    else{cout << ans/2;}

    return 0;
}

