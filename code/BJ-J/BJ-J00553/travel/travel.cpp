#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int cn1,cn2;
    string s1,s2;
    cin>>cn1>>s1>>cn2>>s2;
    int p1,p2;
    char c1,c2;
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    c1=s1[2];
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    c2=s2[2];
    bool f1,f2,f3,f4;
    f1=f2=f3=f4=false;
    if(cn1==cn2)
    {
        f1=true;
        if(p1==p2)
        {
            f2=true;
            if((c1<='C' and c2<='C')or(c1>='D' and c2>='D'))
            {
                f3=true;
                if(c1-c2==1 or c2-c1==1)f4=true;
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
