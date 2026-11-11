#include <bits/stdc++.h>
using namespace std;
string d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    cin >> a;
    for(int i = 1;i <= a;i++)
    {
        cin >> d;
    }
    string b;
    for(int p = 1;p <= a;p++)
    {
        b = d;
    }
    int g = 0;
    for(int y = 1;y <= a;y++)
    {
        for(int i = 0;i < b.size();i++)
        {
            if(b[i] == b[i])
            {
                g++;
            }
        }
    }
    cout << g << endl;
    return 0;
}
