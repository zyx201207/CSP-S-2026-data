#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int c3=(s1[0]-'0')*10+s1[1]-'0',c4=(s2[0]-'0')*10+s2[1]-'0';
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        if(c3!=c4)
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            if(s1[2]<'D' && s2[2]<'D' || s1[2]>'C' && s2[2]>'C')
            {
                cout<<"1";
                if(abs(s1[2]-s2[2])==1 || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D')
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
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
