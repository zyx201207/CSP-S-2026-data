#include<bits/stdc++.h>
using namespace std;
string b;
struct huiwen()
{
    int a;
    char c;
};
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n , cnt = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a;
        getline(cin , c);
        for(int j = 1 ; j <= a ; j++)
        {
            b += c;
        }
    }
    int s = b.size();
    if(s % 2 == 1)
    {
        for(int i = 1; i <=s / 2 ; i++)
        {
            if(b[i] == b[s - i])
            {
                continue;
            }
            else
            {
                b[s - i] = b[i];
                cnt++;
            }
        }
    }
    else
    {
        for(int i =1 ; i <= s/2 ; i++)
        {
            if(b[i] == b[s - i])
            {
                continue;
            }
            else
            {
                b[s-i] = b[i];
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
