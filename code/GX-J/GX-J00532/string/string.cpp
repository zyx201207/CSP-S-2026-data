#include <bits/stdc++.h>
using namespace std;
string S;
long num=0,sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    long b;
    char s;
    cin >> a;
    for (int i = 1;i<=a;i++)
    {
        cin >> b >> s;
        num+=b;
        for (int j = 1;j<=b;j++)
        {
            S+=s;
        }
    }
    for (int i = 0;i<num/2;i++)
    {
        if (S[i]!=S[num-i-1])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
