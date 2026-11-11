#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;

    cin>>c1>>s1>>c2>>s2;
    int p1=(s1[0]-'0')*10+s1[1]-'0';
    int p2=(s2[0]-'0')*10+s2[1]-'0';
    int z1=s1[2]-'A'+1;
    int z2=s2[2]-'A'+1;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(p1!=p2)
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if((z2<=3&&z1<=3)||(z2>3&&z1>3))
    {
        if(abs(z2-z1)==1)
        {
            cout<<"1111"<<endl;
        }
        else
        {
            cout<<"1110"<<endl;
        }
        return 0;
    }
    else
    {

        cout<<"1100"<<endl;
        return 0;
    }
}
