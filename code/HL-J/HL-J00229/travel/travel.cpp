#include<bits/stdc++.h>
using namespace std;

string c1,c2;
string s1,s2;
int num[7]={1,2,3,10,-100,11};
int x,y;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            x=num[s1[2]-'A'];
            y=num[s2[2]-'A'];
            //cout<<x<<" "<<y<<endl;
            if(x-y<=2&&x-y>=-2)
            {
                cout<<"1";
                if(x-y==1||x-y==-1)
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
                //return 0;
            }
        }
        else
        {
            cout<<"000";
            //return 0;
        }
    }
    else
    {
        cout<<"0000";
        //return 0;
    }


    //cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2;
    return 0;
}
