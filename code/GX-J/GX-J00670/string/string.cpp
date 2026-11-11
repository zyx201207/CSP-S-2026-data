#include <iostream>
using namespace std;
int num;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string ci;
        int ai;
        cin >> ai >> ci;
    }
    for(int i = 1;i <= n;i++)
    {
        string s = ai * ci;
        string d += s;
    }
    for(int i = length();i >= 1;i--)
    {
        string e += d[i];
    }
    if(d == e) cout << 0;
    else
    {
        for(int i = 1;i <= e.length() + 1;i++)
        {
            for(int j = 1;j <= d.length() + 1;j++)
            {
                if(e[i] == d[j]) countinue;
                else
                {
                    e[j] = d[i];
                    num++;
                }
                if(d == e)
                {
                    cout << num;
                    break;
                }
            }
        }
    }
    return 0;
}
