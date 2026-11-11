#include<bits/stdc++.h>
using namespace std;

string a,ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    getline(cin,a);
    if(a[0] == a[7]&&a[1] == a[8])
    {
        cout<<"1";
        if(a[3] == a[10]&&a[4] == a[11])
        {
            cout<<"1";
            if((a[5]<='C'&&a[5]>='A'&&a[12]<='C'&&a[12]>='A')||(a[5]<='F'&&a[5]>='D'&&a[12]<='F'&&a[12]>='D'))
            {
                cout<<"1";
                int t = abs(a[5]-a[12]);
                if(t == 1)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
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
