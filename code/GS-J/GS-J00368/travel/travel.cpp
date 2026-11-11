#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int r=s1.length();
    if(c1==c2)
    {
        cout<<"1";
        int f=0;
        for(int i=0;i<r-1;i++)
        {
            if(s1[i]!=s2[i])
            {
                f+=1;
            }
        }
        if(f==0)
        {
            cout<<"1";
            if(s1[r-1]>='A'&&s1[r-1]<='C'&&s2[r-1]>='A'&&s2[r-1]<='C'||s1[r-1]>='D'&&s1[r-1]<='F'&&s2[r-1]>'D')
            {
                cout<<"1";
                if(s1[r-1]-s2[r-1]==1||s2[r-1]-s1[r-1]==1)
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
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
