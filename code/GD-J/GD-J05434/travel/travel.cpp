#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("travel.in","r",stdin);
    freopne("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    int ans = 0;
    if(s1[0] == s2[0] && s1[1] == s2[1] && (s1[2] != 'C' || s2[2] != 'D') &&  s1[2] == 'D' && s2[2] == 'F' )

    {


        cout << "111";

        return 0;

    }
    if(s1[0] == s2[0] && s1[1] == s2[1] && (s1[2] != 'C' || s2[2] != 'D') && abs((s1[2] - s2[2])) == 1 )
    {
        cout << "111";
        return 0;

    }

    else if(s1[0] != s2[0] || s1[1] != s2[1])
    {
        cout << "000";
        return 0;
    }
    else if(s1[0] == s2[0] && s1[1] == s2[1] && abs((s1[2] - s2[2]) != 1))
    {
        if(s1[2] == 'C' && s2[2] == 'D')
        {
            cout << "100";
        }
        else cout << "110";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
