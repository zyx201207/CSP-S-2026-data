#include<bits/stdc++.h>
using namespace std;
char ans[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int h=b[2]-'A'+1;
    int g=d[2]-'A'+1;
    if(a[0]==c[0]&&(a[1]==c[1]))
    {
        ans[1]='1';
    }
    else
    {
        for(int i=1;i<=4;i++) cout<<'0';
        return 0;
    }
    if(b[0]==d[0]&&(b[1]==d[1]))
    {
        ans[2]='1';
        if((h>=4&&(g>=4))||(h<4&&(g<4))) ans[3]='1';
        else
        {
            ans[3]='0';
            ans[4]='0';
            for(int i=1;i<=4;i++) cout<<ans[i];
            return 0;
        }
        if((h==g-1)||(g==h-1))
        {
            ans[4]='1';
        }
        else ans[4]='0';
    }
    else
    {
        ans[2]='0';
        ans[3]='0';
        ans[4]='0';
        for(int i=1;i<=4;i++) cout<<ans[i];
        return 0;
    }
    for(int i=1;i<=4;i++) cout<<ans[i];
    return 0;
}