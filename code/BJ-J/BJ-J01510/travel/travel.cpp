#include<bits/stdc++.h>
using namespace std;
char a2[1001],b2[1001];
int main()
{
    freopen('travel.in','r',stdin);
    freopen('travel.out','w',stdout);
    int a1,b1;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1])
        {
            cout<<1;
            if(((a2[2]>='A'&&a2[2]<='C')&&(b2[2]>='A'&&b2[2]<='C'))||((a2[2]>='D'&&a2[2]<='E')&&(b2[2]>='D'&&b2[2]<='E')))
            {
                cout<<1;
                if(a2[2]+1==b2[2]||b2[2]+1==a2[2])
                {

                    cout<<1;
                }
                else
                {
                    cout<<0;
                    return 0;
                }
            }
            else
            {
                cout<<0<<0;
                return 0;
            }
        }
        else{
            cout<<0<<0<<0;
            return 0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    return 0;
}
