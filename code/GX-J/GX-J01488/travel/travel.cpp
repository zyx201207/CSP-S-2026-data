#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,b;
    string n,m,s,t;
    cin>>n>>s>>m>>t;
    if(n==m)
    {
        cout<<1;
        if(s[0]==t[0] && s[1]==t[1])
        {
            cout<<1;
            x=s[2]-'A';
            b=t[2]-'A';
            if(x>=0 && x<=2)
            {
                if(b>=0 && b<=2)
                {
                    cout<<1;
                    if(x+1==b || x-1==b)
                        cout<<1;
                    else
                        cout<<0;
                }
            }
            else if(x>=3 && x<=5)
            {
                if(x>=3 && x<=5)
                {
                    cout<<1;
                    if(x+1==b || x-1==b)
                        cout<<1;
                    else
                        cout<<0;
                }
            }
            else
                cout<<0<<0;
        }
        else
            cout<<0<<0<<0;
    }
    else
        cout<<0<<0<<0<<0;
    return 0;
}
