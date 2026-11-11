#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string ca, sa, cb, sb;
    cin >> ca >> sa >> cb >> sb;
    if(ca == cb)cout << 1;
    else cout << 0;
    if(ca == cb && sa[0] == sb[0] && sa[1] == sb[1])cout << 1;
    else cout << 0;
    if(ca == cb && sa[0] == sb[0] && sa[1] == sb[1])
    {
        if((sa[2] == 'A' || sa[2] == 'B' || sa[2] == 'C') && (sb[2] == 'A' || sb[2] == 'B' || sb[2] == 'C'))cout << 1;
        else if((sa[2] == 'D' || sa[2] == 'F') && sb[2] == 'D' || sb[2] == 'F')cout << 1;
        else cout << 0;
    }
    else cout << 0;
    if(ca == cb && sa[0] == sb[0] && sa[1] == sb[1])
    {
        if(sa[2] == 'A' && sb[2] == 'B')cout << 1;
        else if(sa[2] == 'B' && (sb[2] == 'A' || sb[2] == 'C'))cout << 1;
        else if(sa[2] == 'C' && sb[2] == 'B')cout << 1;
        else if(sa[2] == 'D' && sb[2] == 'F')cout << 1;
        else if(sa[2] == 'F' && sb[2] == 'D')cout << 1;
        else cout << 0;
    }
    else cout << 0;
    return 0;
}
