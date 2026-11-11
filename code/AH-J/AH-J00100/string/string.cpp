#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, ans = 0;
    cin >> n;
    string str = "";
    for(long long i = 0;i < n;i++){
        long long a;
        cin >> a;
        char ch;
        cin >> ch;
        for(long long j = 0;j < a;j++)
        {
            str+=ch;
        }
    }
    long long l = 0, r = str.length()-1;
    while(l != r)
    {
        if(str[l] != str[r]) ans++;
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
