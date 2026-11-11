#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2;
bool book=0,book1=0,book2=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        book1=1;
    }
    else cout<<0;
    if(book1==0)
    {
        cout<<"000";
        return 0;
    }
    p1=s1.substr(0,2);
    p2=s2.substr(0,2);
    if(p1==p2)
    {
        cout<<1;
        book2=1;
    }
    else cout<<0;
    if(book2==0)
    {
        cout<<"00";
        return 0;
    }
    p1=s1.substr(2,1);
    p2=s2.substr(2,1);
    if((p1<"D"&&p2<"D")||(p1>"C"&&p2>"C"))
    {
        cout<<1;
        book=1;
    }
    else cout<<0;
    if(book==1)
    {
        if(p1>p2) swap(p1,p2);
        if((p1=="A"&&p2=="B")||(p1=="B"&&p2=="C")||(p1=="D"&&p2=="F")) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
