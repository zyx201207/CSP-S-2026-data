#include<bits/stdc++.h>
using namespace std;
string x,xx,y,yy;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int flag = 1;
    cin >> x >> xx >> y >> yy;
    flag &= (x == y);
    cout << flag;
    flag &= (xx[0] == yy[0] && xx[1] == yy[1]);
    cout << flag;
    flag &= ((xx[2] <= 'C' && yy[2] <= 'C') || (xx[2] >= 'D' && yy[2] >= 'D'));
    cout << flag;
    flag &= (abs(xx[2] - yy[2]) == 1);
    cout << flag;
}