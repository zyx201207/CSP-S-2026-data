#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool same_side(char x,char y)
{
    if((x=='D' && y=='F') || (x=='A' && y=='B') || (x=='A' && y=='C') || (x=='B' || y=='C'))return true;
    return false;
}

bool beside(char x,char y)
{
    if((x=='D' && y=='F') || (x=='A' && y=='B') || (x=='B' || y=='C'))return true;
    return false;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;

    //1
    if(c1==c2)cout<<1;
    else cout<<0;

    //2
    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    if(c1==c2 && p1==p2)cout<<1;
    else cout<<0;

    //3
    char seat1=s1[2];
    char seat2=s2[2];
    if(seat1>seat2)swap(seat1,seat2);
    if(c1==c2 && p1==p2 && same_side(seat1,seat2))cout<<1;
    else cout<<0;

    //4
    if(c1==c2 && p1==p2 && beside(seat1,seat2))cout<<1;
    else cout<<0;
    return 0;
}
