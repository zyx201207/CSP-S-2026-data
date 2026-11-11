#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("trvel.out","w",stdout);


    char s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1=c2)
    {
        cout<<"11";
        if(s1=s2)
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
        cout<<"00";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
