#include <iostream>

using namespace std;

const int N = 2;
const int M = 3;
char a_2[N];
char a_3[M];
char b_2[N];
char b_3[M];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    char ch = '\0';
    for (int i = 0; i < 2; i++) a_2[i] = getchar();
    ch = getchar();
    for (int i = 0; i < 3; i++) a_3[i] = getchar();
    ch = getchar();
    for (int i = 0; i < 2; i++) b_2[i] = getchar();
    ch = getchar();
    for (int i = 0; i < 3; i++) b_3[i] = getchar();

    if (a_2[0] == b_2[0] && a_2[1] == b_2[1])
    {
        cout << 1;
        if (a_3[0] == b_3[0] && a_3[1] == b_3[1])
        {
            cout << 1;
            if (a_3[2] <= 'C' && b_3[2] <= 'C' || a_3[2] > 'C' && b_3[2] > 'C')
            {
                cout << 1;
                if (b_3[2] == a_3[2]+1 || b_3[2] == a_3[2]-1 || b_3[2] == 'D' && a_3[2] == 'F' || a_3[2] == 'D' && b_3[2] == 'F')
                {
                    cout << 1;
                }
                else
                {
                    cout << "0" << endl;
                }
            }
            else
            {
                cout << "00" << endl;
            }
        }
        else
        {
            cout << "000" << endl;
        }
    }
    else
    {
        cout << "0000" << endl;
    }
    return 0;
}
