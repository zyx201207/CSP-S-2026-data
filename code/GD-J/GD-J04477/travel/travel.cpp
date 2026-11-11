#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int x1=(s1[0]-'0')*10+s1[1]-'0';
    int x2=(s2[0]-'0')*10+s2[1]-'0';
    int y1=s1[2]-'A';
    int y2=s2[2]-'A';
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        if(x1!=x2)
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            if(y1<=2&&y2<=2)
            {
                cout<<"1";
                if(y1==y2+1||y1==y2-1)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if(y1>=3&&y1<=4&&y2>=3&&y2<=4)
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
            }
        }
    }
    return 0;
}