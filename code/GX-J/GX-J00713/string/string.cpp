#include <bits/stdc++.h>

using namespace std;
char s[1000000005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int js = 0;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin >> a;
        js+=a;
        char b;
        cin >> b;
        for(int j = js-a;j < js;j++)
            s[j] = b;
    }
    int sum = 0;
    for(int i = 0;i < js/2;i++)
    {
        if(s[i] != s[js-i-1])
            sum++;
    }
    cout << sum;
    return 0;
}
