#include<bits/stdc++.h>
using namespace std;
struct train{
    string x , set;
}a ,b;
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool num = true;
    cin >> a.x >> a.set;
    cin >> b.x >> b.set;

    if(a.x == b.x) cout << 1;
    else
    {
        num = false;
        cout << 0;
    }

    if(num && a.set[0] == b.set[0] && a.set[1] == b.set[1])
    {
            cout << 1;
    }
    else
    {
        num = false;
        cout << 0;
    }

    if(num)
    {
        if((a.set[2] >= 'A' && b.set[2] >= 'A' && a.set[2] <= 'C' && b.set[2] <= 'C') || (a.set[2] >= 'D' && b.set[2] >= 'D' && a.set[2] <= 'F' && b.set[2] <= 'F'))
        {
            cout << 1;
        }
        else{
            num = false;
            cout << 0;
        }
    }
    else
    {
        num = false;
        cout << 0;
    }

    if(num && (a.set[2]+1 == b.set[2] || a.set[2]-1 == b.set[2]))
    {
        cout << 1;
    }
    else cout << 0;
    return 0;
}
