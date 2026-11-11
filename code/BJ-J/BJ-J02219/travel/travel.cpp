#include<bits/stdc++.h>
using namespace std;
bool checkl(string s)
{
    if(s.substr(2,1)=="A"||s.substr(2,1)=="B"||s.substr(2,1)=="C")
        return 1;
    return 0;
}
bool checkr(string s)
{
    if(s.substr(2,1)=="D"||s.substr(2,1)=="E")
        return 1;
    return 0;
}
bool checkb(string s1,string s2)
{
    if((s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")||(s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")||(s1.substr(2,1)=="C"&&s2.substr(2,1)=="D")||(s1.substr(2,1)=="D"&&s2.substr(2,1)=="E"))
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool f1,f2,f3;
    cout<<(c1==c2);
    f1=(c1==c2);
    cout<<(f1&&(s1.substr(0,2)==s2.substr(0,2)));
    f2=(f1&&(s1.substr(0,2)==s2.substr(0,2)));
    cout<<(f2&&( (checkl(s1)&&checkl(s2)) || (checkr(s1)&&checkr(s2)) ));
    f3=(f2&&( (checkl(s1)&&checkl(s2)) || (checkr(s1)&&checkr(s2)) ));
    cout<<(f3&&(checkb(s1,s2)||checkb(s2,s1)));
    return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
