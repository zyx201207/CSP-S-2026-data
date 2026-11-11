#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string a[10] = {s1}, b[10] = {s2};
    int t1 = 0 ,t2 = 0;
    if( c1 == c2)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
    }
    for( int i = 0; i <= s1.size(); i++)
    {
        if( a[i] == b[i] and a[i + 1] == b[i + 1] and a[i + 2] == b[i + 2])
        {
            cout << "111";
            break;
        }
        if( a[i] == b[i] and a[i + 1] == b[i + 1] and t1 == 0)
        {
            cout << "1";
            t1 = 1;
        }
        else if(a[i] != b[i] or a[i + 1] != b[i + 1] and t1 == 0)
        {
            cout << "0";
            t1 = 1;
        }
        if( a[i] == "A" and b[i] == "B" or "C" and t2 == 0)
        {
            cout << "1";
            t2 =1;
        }
        else if( a[i] == "B" and b[i] == "A" or "C" and t2 == 0)
        {
            cout << "1";
            t2 =1;
        }
        else if( a[i] == "C" and b[i] == "A" or "B" and t2 == 0)
        {
            cout << "1";
            t2 =1;
        }
        else if( a[i] == "D" and b[i] == "F" and t2 == 0)
        {
            cout<< "1";
            t2 =1;
        }
        else if( a[i] == "F" and b[i] == "D" and t2 == 0)
        {
            cout<< "1";
            t2 =1;
        }
        else
        {
            cout << "0";
            t2 =1;
        }
    }
    return 0;
}
