#include <bits/stdc++.h>
using namespace std;

bool judgec(string x, string y)
{
    if (x[1] == y[1] && x[0] == y[0])
    	return 1;
    return 0;
}
bool judgeb(string x, string y)
{
    if ((x[2] == 'A' && y[2] == 'B')||(x[2] == 'B' && y[2] == 'A')||(x[2] == 'A' && y[2] == 'C')||(x[2] == 'C' && y[2] == 'A')||(x[2] == 'B' && y[2] == 'C')||(x[2] == 'C' && y[2] == 'B')||(x[2] == 'D' && y[2] == 'F'))
        return 1;
    return 0;
}
bool judgea(string x, string y)
{
    if ((x[2] == 'A' && y[2] == 'B')||(x[2] == 'B' && y[2] == 'A')||(x[2] == 'B' && y[2] == 'C')||(x[2] == 'C' && y[2] == 'B')||(x[2] == 'D' && y[2] == 'F'))
        return 1;
    return 0;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    //cout << judgec(c1, c2) << judgec(s1, s2) << judgeb(s1, s2) << judgea(s1, s2) <<endl;
    if (!judgec(c1, c2)){
        cout << "0000";
        return 0;
    }
    if (!judgec(s1, s2)){
        cout << "1000";
        return 0;
    }
    if (!judgeb(s1, s2)){
        cout << "1100";
        return 0;
    }
    if (!judgea(s1, s2)){
        cout << "1110";
        return 0;
    }
    cout << "1111";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

