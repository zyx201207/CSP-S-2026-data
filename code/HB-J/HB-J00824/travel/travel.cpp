#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    char s1[100],s2[100];
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int close=0;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){a=1;}
    char _a=s1[2];
    char _b=s2[2];
    if(s1[0]==s2[0]&&s1[1]==s2[1] && a){
        b++;
    }
    if(_a>='D' && _b>='D' && a)
    {
        c++;
    }else if(_a<='C' && _b<='C' && a)
    {
        c++;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]==s2[2] &&(_a-_b==1 || _b-_a==1)&&a)
    {
        d++;
    }
    cout<<a<<b<<c<<d;
    return 0;

}
