#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S;
    int n,sum = 0,num = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int x;
        string y;
        for (int j = 0;j < x;j++)
            S += y;
    }
    for (int i = S.size();i > -1;i--)
    {
         if (S[i] != S[sum])
         {
             sum++;
             num++;
         }
         else
         {
             sum++;
         }
    }
    cout << sum;
    return 0;
}
