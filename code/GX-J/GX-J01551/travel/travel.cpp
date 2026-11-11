#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int num1,num2;
    string n,m;
    cin>>num1>>n>>num2>>m;
    if(num1==num2)
    {
        if(n[0]==m[0]&&n[1]==m[1])
        {
            if(n[2]<='C'&&m[2]<='C')
            {
                if(abs(n[2]-m[2])==1)
                    cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
