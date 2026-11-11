#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3,f4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    f1 = (s1 == s3);
    if(f1 == 1 && s2[0] == s4[0] && s2[1] == s4[1])
        f2 = 1;
    if(f2 == 1)
    {
        if((s2[2] == 'A' && s4[2] == 'C') || (s2[2] == 'C' && s4[2] == 'A'))
        {
            f3 = 1;f4 = 0;
        }
        else if(s2[2]-s4[2] == 1 || s4[2]-s2[2] == 1)
        {
            f3 = 1;f4 = 1;
        }
        if((s2[2] == 'C' && s4[2] == 'D') || (s2[2] == 'D' && s4[2] == 'C'))
        {
            f3 = 0;f4 = 0;
        }
    }
    cout << f1 << f2 << f3 << f4;
}