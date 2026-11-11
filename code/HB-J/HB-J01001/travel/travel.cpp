#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b)
    {
            cout<<1;
            if(a1[0]==b1[0]&&a1[1]==b1[1])
            {
                int a3=0,a4=0;
                cout<<1;
                if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C')
                {
                    a3=1;

                }
                if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')
                {
                    a4=1;

                }
                if(a3==a4)
                {

                    cout<<1;
                    if(((a1[2]-1)==(int)b1[2])||((a1[2]+1)==(int)b1[2]))
                    {

                        cout<<1;
                    }
                    else
                    {

                        cout<<0;
                    }
                }
                else
                {

                    cout<<0<<0;
                }
            }
            else
            {

                cout<<0<<0<<0;
            }
    }
    else
    {

        cout<<0<<0<<0<<0;
    }

    return 0;
}

