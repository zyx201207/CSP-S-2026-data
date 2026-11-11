#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c1,r1,c2,r2;
    char s1,s2;
    cin>>c1>>r1>>s1>>c2>>r2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(r1==r2)
        {
            cout<<1;
            if((int(s1)<=67 && int(s2)<=67) || int(s1)>67 && int(s2)>67)
            {
                cout<<1;
                if(abs(int(s1)-int(s2))<=1 || (s1=='D' && s2=='F')) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
