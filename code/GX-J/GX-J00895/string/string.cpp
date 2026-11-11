#include <iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a;
    cin >> n;
    for (int i = 1 ; i <= n;i++)
    {
        int s;
        char b;
        cin >> s >> b;
        for (int j = 1;j <= s;j++)
        {
            a += b;
        }
    }
    cout << 0;
    return 0;
}
