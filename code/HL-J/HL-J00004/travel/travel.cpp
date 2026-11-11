#include<bits/stdc++.h>
using namespace std;
void check(string s1,string s2)
{
    string sd,sf;
    for(int i=0;i<s1.size()-1;i++)
    {
        sd+=s1[i];
        sf+=s2[i];
    }
    if(sd==sf)
    {
        cout<<"1";
        if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') )
        {
            cout<<"1";
            if(abs(s1[2]-s2[2])==1) cout<<"1";
            else cout<<"0";
        }
        else cout<<"00";

    }
    else cout<<"000";

}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        check(s1,s2);
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
