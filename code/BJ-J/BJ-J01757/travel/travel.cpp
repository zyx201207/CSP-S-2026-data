#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i = 0;i <= 1;i++)
    {
        if(c1[i] != c2[i])
        {
            cout << "0000";
            return 0;
        }
    }
    for(int i = 0;i <= 1;i++)
    {
        if(s1[i] != s2[i])
        {

            cout << "1000";
            return 0;
        }
    }
    char a = s1[2],b = s2[2];
    if((!(a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F')) && (!(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C')))
    {

        cout << "1100";
        return 0;
    }
    if(a <= 'C' && b <= 'C' )
    {
        if(abs(a - b) > 1)
        {

            cout << "1110";
            return 0;
        }
    }
    cout << "1111";
}
