#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,s1,c2,s2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        exit(0);
    }
    cout<<1;
    int x1=(s1[0]-'0')*10+(s1[1]-'0');
    int x2=(s2[0]-'0')*10+(s2[1]-'0');
    if(x1!=x2)
    {
        cout<<"000"<<endl;
        exit(0);
    }
    cout<<1;
    int seat1=(s1[2]-'A'+1),seat2=(s2[2]-'A'+1);
    bool side1=(1<=seat1&&seat1<=3),side2=(1<=seat2&&seat2<=3);
    if(side1!=side2)
    {
        cout<<"00"<<endl;
        exit(0);
    }
    cout<<1<<(abs(seat1-seat2)==1);
    return 0;
}