#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int m,n;
    string m1,n1;
    cin >> m >> m1 >> n >> n1;
    if(m!=n)
    {
        cout << "0000";
    }
    else
    {
        cout << "1";
        if(m1[1]!=n1[1])
        {
            cout << "000";
        }
        else
        {
            cout <<"1";
            if(m1[2]=='E'||m1[2]=='F')
            {
                if(n1[2]=='E'||n1[2]=='F')
                {
                    cout << "11";
                }
                else
                {
                    cout << "00";
                }
            }
            else
            {
                if(n1[2]=='C'||n1[2]=='A'||n1[2]=='B')
                {
                    cout << "1";
                    if(m1[2]=='A'&&n1[2]=='C')
                    {
                        cout << "0";
                    }
                    if(m1[2]=='C'&&n1[2]=='A')
                    {
                        cout << "0";
                    }
                    else
                    {
                        cout << "1";
                    }
                }
                else
                {

                    cout << "00";
                }
            }
        }
    }
    return 0;
}
