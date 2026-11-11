#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int l1=(s1[0]-'0')*10+(s1[1]-'0');
    int l2=(s2[0]-'0')*10+(s2[1]-'0');
    char zw1=s1[2],zw2=s2[2];
    if(c1!=c2)
    {
        cout<<"0000\n";
        return 0;
    }
    else if(l1!=l2)
    {
        cout<<"1000\n";
        return 0;
    }
    else if((zw1>='A'&&zw1<='C')&&(!(zw2>='A'&&zw2<='C')))
    {
        cout<<"1100\n";
    }
    else if((zw1=='D'||zw1=='F')&&(!(zw2=='D'||zw2=='F')))
    {
        cout<<"1100\n";
    }
    else if(abs(zw1-zw2)!=1)
    {
        cout<<"1110\n";
    }
    else
    {
        cout<<"1111\n";
    }
    return 0;
}