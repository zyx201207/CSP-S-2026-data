#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<"1";
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }
    int a=(s2[0]-'0')*10+(s2[1]-'0');
    int b=(s4[0]-'0')*10+(s4[1]-'0');
    if(a==b)cout<<"1";
    else
    {
        cout<<"000"<<endl;
        return 0;
    }
    char c=(s2[2]-'A'),d=(s4[2]-'A');
    if(((c==0||c==1||c==2)&&(d==0||d==1||d==2))||((c==3||c==5)&&(d==3||d==5)))cout<<"1";
    else
    {
        cout<<"00"<<endl;
        return 0;
    }
    if((c==0&&d==1)||(c==1&&d==2)||(c==3&&d==5))cout<<"1";
    else
    {
        cout<<"0";
        return 0;
    }
    return 0;
}
