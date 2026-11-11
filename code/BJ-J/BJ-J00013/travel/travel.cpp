#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    bool B1=(s1==s3);
    string s5=s2.substr(0,1);
    string s6=s4.substr(0,1);
    bool B2=B1&&(s5==s6);
    bool B3=B2&&((s2[2]<=67&&s4[2]<=67)||(s2[2]>67&&s4[2]>67));
    bool B4=B3&&(abs(char(s2[2])-char(s4[2]))==1||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D');
    cout<<B1<<B2<<B3<<B4;
    return 0;
}
