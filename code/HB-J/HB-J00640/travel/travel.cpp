#include <bits/stdc++.h>
using namespace std;
void quick_oi()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie();
}
void sol()
{
    int a1, a2, b1, b2;
    char cha, chb;
    cin >> a1 >> a2 >> cha >> b1 >> b2 >> chb;
    vector<set<char>> book(10, set<char>());
    book[1].insert('B');
    book[2].insert('A');
    book[2].insert('C');
    book[3].insert('B');
    book[4].insert('F');
    book[5].insert('D');
    cout << (a1 == b1) ? 1 : 0;
    cout << ((a1 == b1) && (a2 == b2)) ? 1 : 0;
    cout << ((a1 == b1) && (a2 == b2) && ((('A' <= cha && cha <= 'C') && ('A' <= chb && chb <= 'C')) || ((cha == 'D' || cha == 'F') && (chb == 'D' || chb == 'F')))) ? 1 : 0;
    cout << ((a1 == b1) && (a2 == b2) && ((('A' <= cha && cha <= 'C') && ('A' <= chb && chb <= 'C')) || ((cha == 'D' || cha == 'F') && (chb == 'D' || chb == 'F'))) && book[(int)(cha - 'A' + 1)].count(chb)) ? 1 : 0;
}
int main()
{
    quick_oi();
    sol();
    return 0;
}
/*

*/