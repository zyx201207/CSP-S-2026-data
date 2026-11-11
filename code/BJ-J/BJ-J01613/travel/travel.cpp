#include <bits/stdc++.h>
using namespace std;
long long a1,b1;
string a2,b2;
long long paia,paib;
char za,zb;
int f = 0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a1>>a2>>b1>>b2;
    if(a1 == b1)
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    paia = (a2[0] - 48) * 10 + a2[1] - 48;
    paib = (b2[0] - 48) * 10 + b2[1] - 48;
    //cout<<endl<<paia<<' '<<paib<<endl;
    if(paia == paib)
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }

    if(a2[2] == 'A'||a2[2] == 'B'||a2[2] == 'C')
    {
        if(b2[2] == 'A'||b2[2] == 'B'||b2[2] == 'C')
        {
            cout<<1;
            if(a2[2] == 'A'&&b2[2] == 'B')
                f = 1;
            if(a2[2] == 'B'&&b2[2] == 'A')
                f = 1;
            if(a2[2] == 'B'&&b2[2] == 'C')
                f = 1;
            if(a2[2] == 'C'&&b2[2] == 'B')
                f = 1;//02 01C 02 01D
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else if(b2[2] == 'D'||b2[2] == 'F')
    {
        cout<<"11";
        return 0;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(f == 1)
        cout<<1;
    else
        cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
