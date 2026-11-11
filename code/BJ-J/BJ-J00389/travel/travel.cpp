#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string car1, seat1, car2, seat2;
    cin >> car1 >> seat1 >> car2 >> seat2;
    if(car1 == car2) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(seat1.substr(0, 2) == seat2.substr(0, 2)) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    if((seat1[2] == 'A' && seat2[2] == 'B') || (seat1[2] == 'A' && seat2[2] == 'C')
    || (seat1[2] == 'B' && seat2[2] == 'A') || (seat1[2] == 'B' && seat2[2] == 'C')
    || (seat1[2] == 'C' && seat2[2] == 'A') || (seat1[2] == 'C' && seat2[2] == 'B')
    || (seat1[2] == 'D' && seat2[2] == 'F') || (seat1[2] == 'F' && seat2[2] == 'D'))
        cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if((seat1[2] == 'A' && seat2[2] == 'B') || (seat1[2] == 'B' && seat2[2] == 'A')
    || (seat1[2] == 'B' && seat2[2] == 'C') || (seat1[2] == 'C' && seat2[2] == 'B')
    || (seat1[2] == 'D' && seat2[2] == 'F') || (seat1[2] == 'F' && seat2[2] == 'D'))
        cout << 1;
    else
    {
        cout << "0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
