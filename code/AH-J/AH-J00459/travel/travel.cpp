#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1) cout<<"0000";
    else
    {
        if(a2.substr(0,2)!=b2.substr(0,2)) cout<<"1000";
        else
        {
            char a=a2[2],b=b2[2];
            if(a>b) swap(a,b);
            if(a>='A'&&a<='C'&&b>='D'&&b<='F') cout<<"1100";
            else
            {
                if(int(b-a)!=1) cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
