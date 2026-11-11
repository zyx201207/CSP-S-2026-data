#include <bits/stdc++.h>
using namespace std;

bool ch(int a,int b)
{
    if (a<=3 && b<=3) return 1;
    else if (a>3 && b>3) return 1;
    return false;
}
bool ch2(int a,int b)
{
    if (a-b==1 || b-a==1) return 1;
    return false;
}
int main()
{
    fropen("travel.in","r","stdin");
    fropen("travel.out","w","stdout");
    string a1,a2,b1,b2;
    cin >>a1>>b1>>a2>>b2;
    if (a1==a2)
    {
        cout <<1;
    }
    else
    {
        cout <<"0000"<<endl;
        return 0;
    }
    if (b1[0]==b2[0] && b1[1]==b2[1])
    {
        cout <<1;
    }
    else
    {
        cout <<"000"<<endl;
        return 0;
    }
    if (ch(int(b1[2]-'A'+1),int(b2[2]-'A'+1)))
    {
        cout <<1;
    }
    else
    {
        cout <<"00"<<endl;
        return 0;
    }
    if (ch2(int(b1[2]-'A'+1),int(b2[2]-'A'+1)))
    {
        cout <<1;
    }
    else
    {
        cout <<0;
    }
    return 0;
}

