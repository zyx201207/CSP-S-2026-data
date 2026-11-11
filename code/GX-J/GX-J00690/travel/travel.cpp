#include <iostream>

using namespace std;
bool t=true;
char c1[2],s1[3],c2[2],s2[3];
int is1,is2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //cout << "Hello world!" << endl;
    cin>>c1>>s1>>c2>>s2;
    is1=int(c1[0]-'0')*10+int(c1[1]-'0');
    is2=int(c2[0]-'0')*10+int(c2[1]-'0');
    if(t&&is1==is2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        t=false;
    }
    is1=int(s1[0]-'0')*10+int(s1[1]-'0');
    is2=int(s2[0]-'0')*10+int(s2[1]-'0');
    if(t&&is1==is2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        t=false;
    }
    if(t)
    {
        if(s1[2]<='C'&&s2[2]<='C')
        {
            cout<<1;
            if((s1[2]+1==s2[2]||s2[2]+1==s1[2]))
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
            return 0;
        }
        else if(s1[2]>='D'&&s2[2]>='D')
        {
            cout<<1<<1;
            return 0;
        }
        else
        {
            cout<<0;
            t=false;
        }
    }
    else
    {
        cout<<0;
        t=false;
    }
    cout<<0;
    return 0;
}
