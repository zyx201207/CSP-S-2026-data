//GZ-J00422,贵阳市南明区华麟学校,张柏塾
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string z1=" ",z2=" ";
    for (int i=0;i<=1;i++)
    {
        z1+=s1[i];
        z2+=s2[i];

    }
    if(c1==c2)
    {
        cout<<'1';
        if(z1==z2)
        {
            cout<<'1';
            if(((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s2[2]=='A'&&(s1[2]=='B'||s1[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C'))||(s2[2]=='C'&&(s1[2]=='A'||s1[2]=='B'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||((s1[1]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[1]=='F'))))
            {
                cout<<'1';
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
                {
                    cout<<'1';
                }
                else
                {
                    cout<<'0';
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}

