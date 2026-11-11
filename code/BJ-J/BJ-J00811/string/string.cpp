#include <bits/stdc++.h>
using namespace std;
int a[100010];
char c[100010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, cnt = 0;
    cin >>n;
    string num = "";
    for(int i = 1; i <= n; i++)
    {

        cin >> a[i] >>c[i];
        for(int j = 1; j <= a[i]; j++)
        {
            num += c[i];
        }
    }
    for(int i = 0; i <= num.size() - i; i++)
    {
        int j = num.size() - i ;
        if(num[i] != num[j]) cnt++;
    }
    cout << cnt ;
    return 0;
}