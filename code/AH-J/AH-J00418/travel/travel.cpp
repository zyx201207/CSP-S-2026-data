#include <bits/stdc++.h>
using namespace std;

char car1[2], seat1[3], car2[2], seat2[3]; 
bool t[5] = {1, 1, 1, 0, 0};

int main ()
{
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    
    scanf ("%s%s%s%s", car1, seat1, car2, seat2);
    int x = (car1[0] - '0') * 10 + car1[1] - '0';
    int y = (car2[0] - '0') * 10 + car2[1] - '0';
    int a = (seat1[0] - '0') * 10 + seat1[1] - '0', aa = seat1[2] - 'A';
    int b = (seat2[0] - '0') * 10 + seat2[1] - '0', bb = seat2[2] - 'A';
    bool f = 1;
    
    if (x == y) putchar ('1');
    else putchar ('0'), f = 0;
    
    if (a == b && f) putchar ('1');
    else putchar ('0'), f = 0;
    
    if (t[aa] == t[bb] && f) putchar ('1');
    else putchar ('0'), f = 0;
    
    if (abs (aa - bb) == 1 && f) putchar ('1');
    else putchar ('0');
    
    return 0;
}
