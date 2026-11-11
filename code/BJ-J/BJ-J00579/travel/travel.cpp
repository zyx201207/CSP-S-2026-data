#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long rc,xc;
    string rz,xz;
    cin >> rc >> rz >> xc >> xz;
    if(rc != xc)
    {
        cout << "0000";
        return 0;
    }
    else
    {
        cout << "1";
        if(rz[0] != xz[0] || rz[1] != xz[1])
        {
            cout << "000";
            return 0;
        }
        else
        {
            cout << "1";
            if(rz[2]<= 'C'&&rz[2] >= 'A')
            {
                if(xz[2] >= 'D')
                {
                    cout << "00";
                    return 0;
                }
                else
                {
                    cout << "1";
                    if(abs(rz[2]-xz[2]) == 1)
                    {
                        cout << "1";
                    }
                    else
                    {
                        cout << "0";
                    }
                }
            }
            else
            {
                if(xz[2] <= 'c')
                {
                    cout << "00";
                    return 0;
                }
                else
                {
                    cout << "1";
                    if(abs(rz[2]-xz[2]) == 1)
                    {
                        cout << "1";
                    }
                    else
                    {
                        cout << "0";
                    }
                }

            }
        }
    }
    return 0;
}
