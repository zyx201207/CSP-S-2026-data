#include <bits/stdc++.h>
using namespace std;
int dg(char z)
{
    map<char,int> last;
    last['A'] = 1;
    last['B'] = 2;
    last['C'] = 3;
    last['D'] = 4;
    last['E'] = 5;
    int t = int(z);
    t-= 64;
    return t;
}

string a,b,c,d;
bool flag[15];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        flag[1] = 1;
    }
    if(b[0] == d[0] && b[1] == d[1] && flag[1] == 1)
    {
        flag[2] = 1;
    }
    int x = dg(b[2]),y = dg(d[2]);
    if(x <= 3 && y <= 3 && flag[2] == 1)
    {
        flag[3] = 1;
    }
    if(x >= 4 && y >= 4 && flag[2] == 1)
        flag[3] = 1;
    if(abs(x - y) == 1 && flag[3] == 1)
        flag[4] = 1;
    for(int i = 1;i <= 4;i++)
    {
        if(flag[i] == 0)
                flag[i + 1] = 0;
        cout << flag[i];
    }

    return 0;
}


