#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else
    {
        cout<<"1";
        int r_num=(s1[0]-'0')*10+(s1[1]-'0');
        int x_num=(s2[0]-'0')*10+(s2[1]-'0');
        if(r_num!=x_num)
        {
            cout<<"000";
        }
        else
        {
            cout<<"1";
            bool flag_r=(s1[2]>='A'&&s1[2]<='C');
            bool flag_x=(s2[2]>='A'&&s2[2]<='C');
            if(flag_r!=flag_x)
            {
                cout<<"00";
            }
            else
            {
                cout<<"1";
                char r_str=s1[2];
                char x_str=s2[2];
                if(flag_r==true&&flag_x==true)
                {
                    if((r_str==x_str+1)||(r_str+1==x_str))
                    {
                        cout<<"1";
                    }
                    else
                    {
                        cout<<"0";
                    }
                }
                else if(flag_r==false&&flag_x==false)
                {
                    cout<<"1";
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}