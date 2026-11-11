#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(a1==a3)
    {
        a=true;
        if(a2[0]==a4[0]&&a2[1]==a4[1])
        {
            b=true;
            if((a2[2]<='C'&&a4[2]<='c')||(a2[2]>='D'&&a4[2]>='D'))
            {
                c=true;
                if(abs(a2[2]-a4[2])==1)
                {
                    d=true;
                }
            }
        }
    }
    cout<<a<<b<<c<<d<<endl;
    return 0;
}