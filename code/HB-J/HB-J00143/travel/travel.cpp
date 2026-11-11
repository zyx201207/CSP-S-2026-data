#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("travel.in", "r", stdin);
    //freopen("travel.out", "w", stdout);
    int c1, c2;
    int s1, s2;
    char ss1, ss2;
    cin >> c1 >> s1 >> ss1;
    cin >> c2 >> s2 >> ss2;
    if(c1 == c2)
    {
        cout << 1;
        if(s1 = s2)
        {
            cout << 1;
            if(ss1 == "D" && ss2 == "F")
            {
                cout << "11";
            }
            else if(ss1 == "F" && ss2 == "D")
            {
                cout << "11";
            }
            else if(ss1 == "D" ss2 != "F")
            {
                cout << "00";
            }
            else if(ss1 == "F" ss2 != "D")
            {
                cout << "00";
            }
            else if(ss1 == "A" && ss2 == "B")
            {

                cout << "11";
            }
            else if(ss1 == "B" && ss2 == "A")
            {

                cout << "11";
            }
            else if(ss1 == "A" && ss2 == "C")
            {

                cout << "10";
            }
            else if(ss1 == "C" && ss2 == "A")
            {

                cout << "10";
            }
            else if(ss1 == "B" && ss2 == "C")
            {

                cout << "11";
            }
            else if(ss1 == "C" && ss2 == "B")
            {

                cout << "11";
            }
            else if(ss1 == "A" && ss2 != "B" && ss2 != "C")
            {

                cout << "00";
            }
            else if(ss1 == "B" && ss2 != "A" && ss2 != "C")
            {

                cout << "00";
            }
            else if(ss1 == "C" && ss2 != "A" && ss2 != "B")
            {

                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else if(c1 != c2)
    {
   cout << "0000";
    }
    return 0;
}
