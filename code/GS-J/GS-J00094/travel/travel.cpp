#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string a1,b1;
int a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b)
    {
        cout<<"1";
        if(a1[0]==b1[0]&&a1[1]==b1[1])
        {
            cout<<"1";
                if((a1[2]<'D'&&b1[2]<'D')||(a1[2]>='D'&&b1[2]>='D'))
                {
                    cout<<"1";
                    int aa=(int)a1[2],bb=(int)b1[2];
                    if(aa+1==bb||aa-1==bb)
                        cout<<"1";
                    else
                        cout<<"0";
                }
                else
                    cout<<"00";
        }
        else
            cout<<"000";
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
