//GZ-J00281 qiuyirong
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a[2];
    string b[3];
    string c[2];
    string d[3];
    cin>>a[2];
    cin>>b[3];
    cin>>c[2];
    cin>>d[3];
    if(a+0==c+0)
    {
        cout<<"1";
        if((b[0]==d[0])&&(b[1]==d[1]))
        {
            cout<<"1";

            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
            {
                cout<<"1";
                if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C'))
                {
                    cout<<"1";
                }
                else
                {

                    cout<<"0";
                }

            }
            else if(b=='D'||b='E'&&d=='D'||d='E')
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {

            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
