#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    int x1=0,x2=0,l=1,a=0,b=0;
    cin>>c1>>s1>>c2>>s2;
    for(int i=s1.size();i>1;i--)
    {
        if(s1[i]>='A'&&s1[i]<='Z')
        {
            a=s1[i];
        }
        if(s1[i]<'A')
        {
            x1+=s1[i]*l;
            l*=10;
        }
    }for(int i=s2.size();i>1;i--)
    {
        if(s2[i]>='A'&&s2[i]<='Z')
        {
            a=s2[i];
        }
        if(s2[i]<'A')
        {
            x2+=s2[i]*l;
            l*=10;
        }
    }
    if(c1==c2)
    {
        cout<<1;
        if(x1==x2)
        {
            cout<<1;
            if(x1%5!=3&&x2%5!=4)
            {
                cout<<1;
                if(a+1==b)
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
        else
        {
            cout<<0<<0<<0;
            return 0;
        }
    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
