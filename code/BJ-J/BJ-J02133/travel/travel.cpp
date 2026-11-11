#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
        string a1;
        string a2;
        a1 = s1[0] + s1[1];
        a2 = s2[0] + s2[1];
        if(a1 == a2)
        {
            cout << 1;
            a1= s1[2];
            a2 = s2[2];
            if(a1 == "A"||a1 == "B" ||a1 == "C")
            {
                if(a2 == "A"||a2 == "B" ||a2 == "C")
                {
                    cout << 1;
                    if(a1 == "A"|| a1 == "C")
                    {
                        if(a2 == "A"|| a2 == "C")
                        {
                            cout << 0;
                        }
                        else
                        {
                            cout << 1;
                        }
                    }
                    else
                    {
                        cout << 1;
                    }
                }
                else{
                    cout << "00";
                }
            }
           if(a1 == "E"|| a1 == "F")
            {
                if(a2 == "E"|| a2 == "F")
                {
                    cout << 11;
                }
                else{
                    cout << "00";
                }
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
}
