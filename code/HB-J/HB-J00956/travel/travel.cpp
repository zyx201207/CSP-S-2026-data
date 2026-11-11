#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,d;
    cin>>c1>>s1>>c2>>s2;
    int a1=(c1[0]-'0')*10+c1[1]-'0';
    int a2=(c2[0]-'0')*10+c2[1]-'0';
    if(a1==a2)
    {
        d+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            d+="1";
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
            {
                d+="1";
                int a=s1[2],b=s2[2];
                if(abs(a-b)==1)
                {
                    d+="1";
                }
            }
        }
    }
    while(d.size()<4)
    {
        d+="0";
    }
    cout<<d;
    return 0;
}
