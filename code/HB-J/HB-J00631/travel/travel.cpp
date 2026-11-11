#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        cout << '1';
        string s3=s1.substr(0,2);
        string s4=s2.substr(0,2);
        if(s3==s4)
        {
            cout << '1';
            if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) || ((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')))
            {
                cout << '1';
                if(!((s1[2]=='A'&&s2[2]=='C') || (s1[2]=='C'&&s2[2]=='A')))
                {
                    cout << '1';
                }
                else
                {
                    cout << '0';
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
