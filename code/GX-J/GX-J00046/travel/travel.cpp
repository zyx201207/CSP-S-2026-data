#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=0,b=0;
    char c1[100],c2[100],s1[100],s2[100];
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
            {
                a=s1[2]-s2[2];
                b=s2[2]-s1[2];
                if(a==1||b==1)
                {
                    cout<<1111;
                }
                else
                {
                    cout<<1110;
                }
            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
            {
                cout<<1111;
            }
            else
            {
                cout<<1100;
            }

        }
        else
        {
            cout<<1000;
        }
    }
    else
    {
        cout<<0000;
    }
    fclose(stdin);
    fclose(stdout);
}
