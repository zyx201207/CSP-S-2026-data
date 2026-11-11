#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1)
        cout<<'1';
    else
        cout<<'0';
    for(int i=0;i<3;i++)
    {
        if(i<2)
        {
            if(c2[i]==s2[i])
                cout<<'1';
            else
                cout<<'0';
        }
        else
        {
            if(c2[i]>='A'&&c2[i]<='C'&&s2[i]>='A'&&s2[i]<='C'||c2[i]=='D'&&c2[i]=='F'&&s2[i]=='D'&&s2[i]=='F')
            {
                cout<<'1';
                if(c2[i]==s2[i]+1||c2[i]==s2[i]-1)
                    cout<<'1';
                else
                    cout<<'0';
            }
            else
                cout<<'0';
        }
    }
    return 0;
}
