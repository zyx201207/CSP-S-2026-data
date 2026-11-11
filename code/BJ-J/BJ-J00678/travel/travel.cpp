#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    int x1,x2,y1,y2;
    x1=(b[0]-'0')*10+b[1]-'0';
    x2=(d[0]-'0')*10+d[1]-'0';
    y1=b[2]-'A'+1;
    y2=d[2]-'A'+1;
    if(a!=c)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(x1!=x2)
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if((y1>3)^(y2>3))
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(!(y1>3||abs(y1-y2)==1))
    {
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}
