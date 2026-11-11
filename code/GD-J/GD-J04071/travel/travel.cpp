#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else if(s1.substr(0,2)!=s2.substr(0,2))cout<<"1000";
    else if((s1.back()<='C')!=(s2.back()<='C'))cout<<"1100";
    else
    {
        char x=s1.back(),y=s2.back();
        if(x>y)swap(x,y);
        if((x=='D'&&y=='F')||(y-x==1))cout<<"1111";
        else cout<<"1110";
    }
    return 0;
}