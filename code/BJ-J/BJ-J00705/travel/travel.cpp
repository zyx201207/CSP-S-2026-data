#include <iostream>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int ache, bche;
    string ahao, bhao;
    cin >> ache >> ahao >> bche >> bhao;
    if (ache == bche)
    {
        cout << "1";
    }
    else
    {
        cout << "0000" << endl;
        return 0;
    }
    if (ahao[0] == bhao[0] && ahao[1] == bhao[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000" << endl;
        return 0;
    }
    if ((ahao[2] <= 'C' && bhao[2] <= 'C') || (ahao[2] > 'C' && bhao[2] > 'C'))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }
    if ((ahao[2] <= 'C' && bhao[2] <= 'C' && abs(ahao[2] - bhao[2]) == 1) || (ahao[2] > 'C' && bhao[2] > 'C'))
    {
        cout << 1;
    }
    else cout << 0;
    return 0;
}
