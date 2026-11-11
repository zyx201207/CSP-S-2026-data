#include <iostream>

using namespace std;
int c1, c2, s1, s2;
char ch1, ch2;

bool check(char cc1, char cc2)
{
    if((cc1 == 'D' && cc2 == 'F') || (cc1 == 'F' && cc2 == 'D'))
    {
        return 1;
    }
    if((cc1 == 'A' && cc2 == 'B') || (cc1 == 'B' && cc2 == 'A'))
    {
        return 1;
    }
    if((cc1 == 'C' && cc2 == 'B') || (cc1 == 'B' && cc2 == 'C'))
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
    if(c1 != c2)
    {
        cout << "0000";
    }
    else
    {
        if(s1 != s2)
        {
            cout << "1000";
        }
        else
        {
            if(check(ch1, ch2))
            {
                cout << "1111";
            }
            else
            {
                if((ch1 == 'A' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'A'))
                {
                    cout << "1110";
                }
                else
                {
                    cout << "1100";
                }
            }
        }
    }
	return 0;
}
