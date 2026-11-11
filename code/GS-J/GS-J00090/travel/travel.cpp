
#include <bits/stdc++.h>

using namespace std;

int isSameC, isSameLine, isSameSide, isNear;
int RC, XC;
string Rseat, Xseat;
int main()
{
    freopen("travel.in", "r",stdin );
    freopen("travel.out", "w", stdout);
    cin >> RC >> Rseat >> XC >>Xseat;
    int ra = Rseat[0], rb = Rseat[1], rc = Rseat[2], xa = Xseat[0], xb = Xseat[1], xc = Xseat[2];

    //A 65   B 66    C 67    D 68    F 70
    if(RC == XC)
    {
        isSameC = 1;
        if(ra == xa && rb == xb)
        {
            isSameLine = 1;
            bool aaa = (rc == 65 && xc == 66 );//1
            bool aab = (rc == 65 && xc == 67 );
            bool aba = (rc == 66 && xc == 65);//2
            bool abb = (rc == 66 && xc == 67);//3
            bool aca = (rc == 67 && xc == 65);
            bool acb = (rc == 67 && xc == 66);//4
            bool baa = (rc ==  68 && xc == 70);//5
            bool bab = (rc == 70 && xc == 68);//6
            if(aaa || aab || aba || abb || aca ||acb || baa || bab)
            {
                isSameSide = 1;
                if(aaa || aba || abb || acb || baa || bab)
                {
                    isNear = 1;
                }
            }
        }
    }
    cout << isSameC << isSameLine << isSameSide << isNear;


    return 0;

}
