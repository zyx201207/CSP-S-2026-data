#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,num1,s2,num2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>num1>>s2>>num2;
    //1
    ll h=0;
    if(s1==s2)
    {

        cout<<1;
        h=1;
    }
    else cout<<0;
    //2
    ll flag=1;
    if(h==1)
    {
        for(ll i=0;i<2;i++)
        {
            if(num1[i]!=num2[i])
            {
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    else
    {
        cout<<0;
        flag=0;
    }
    //3
    ll f=0;
    if(flag==1)
    {
        if((num1[2]<='C'&&num2[2]<='C')||(num1[2]>='D'&&num2[2]>='D'))
        {
            cout<<1;
            f=1;
        }
        else cout<<0;
    }
    else cout<<0;
    //4
    ll x=abs(num1[2]-num2[2]);
    if(x==1&&flag==1&&f==1)cout<<1;
    else cout<<0;
    return 0;
}
