#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,A,B;
    cin >> a >> A >> b >> B;
    if (a != b)
    {
        cout << "0000";
    }
    else if (A[0] != B[0] || A[1] != B[1])
    {
        cout << "1000";
    }
    else if ((A[2] == "F" && B[2] == "D") || (A[2] == "D" && B[2] == "F") || (A[2] == "C" && B[2] == "B") || (A[2] == "B" && B[2] == "C") || (A[2] == "C" && B[2] == "A") || (A[2] == "A" && B[2] == "C") || (A[2] == "B" && B[2] == "A") || (A[2] == "A" && B[2] == "B"))
    {
        if ((A[2] == "F" && B[2] == "D") || (A[2] == "D" && B[2] == "F") || (A[2] == "C" && B[2] == "B") || (A[2] == "B" && B[2] == "C") || (A[2] == "B" && B[2] == "A") || (A[2] == "A" && B[2] == "B"))
        {
            cout << "1111";
        }
        else
        {

            cout << "1110";
        }
    }
    else
    {
        cout << "1100";
    }
}
