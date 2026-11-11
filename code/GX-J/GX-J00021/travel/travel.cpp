#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,c1,c2,N,M;
    cin>>x1>>x2>>c1>>c2;
    N=x2[2];
    M=c2[2];
    if(x1==c1)
    {
        cout<<"1";
        if((x2[0]==c2[0])&&(x2[1]==c2[1]))
        {
            cout<<"1";
            if(((N<="C")&&(M<="C"))||(("C"< N)&&("C"< N)))
            {
                cout<<"1";
                if(1/2==1)
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
