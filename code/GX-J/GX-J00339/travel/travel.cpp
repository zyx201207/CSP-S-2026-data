#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;
int a1,a2,ol,ob;

int main()
{
    //tijiao qian jide qu zhushi
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s2[2]>='A'&&s2[2]<='C')//s2
        a1=1;
    else
        a1=2;
    if(s4[2]>='A'&&s4[2]<='C')//s4
        a2=1;
    else
        a2=2;
    if(s1==s3)//first
    {
        cout<<1;
        ob=1;
    }
    else
        cout<<0;
    //cout<<s2[1]+s2[2]<<' '<<s4[1]+s4[2]<<endl;
    if(s2[0]+s2[1]==s4[0]+s4[1]&&ob==1){//second
        cout<<1;
        ol=1;
    }
    else
        cout<<0;
    if(ol==1&&a1==a2&&ob==1)//third
        cout<<1;
    else
        cout<<0;
    if(abs(s2[2]-s4[2])==1&&a1==a2&&ol==1&&ob==1)//4nd
        cout<<1;
    else
        cout<<0;
    return 0;
}
