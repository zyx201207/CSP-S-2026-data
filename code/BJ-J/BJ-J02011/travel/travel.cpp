#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,y1;
    int x,y;
    cin>>x>>x1>>y>>y1;
    string ans="";
    if(x==y) ans+="1";
    else ans+="0";
    int x2=0,y2=0,a=0,b=0;
    for(int i=0;i<2;i++)
    {
        x2=x2*10+(x1[i]-'0');
        y2=y2*10+(y1[i]-'0');
    }
    a=x1[2]-'A'+1;
    b=y1[2]-'A'+1;
    if(ans=="1")
    {
        if(x2==y2)
        {
            ans+="1";
            if(1<=a&&a<=3&&1<=b&&b<=3) ans+="1";
            else if(4<=a&&a<=6&&4<=b&&b<=6) ans+="1";
            if(ans=="111")
            {
            if(a==1)
            {
                if(b==2) ans+="1";
                else ans+="0";
            }
            else if(a==2)
            {
                if(b==1||b==3) ans+="1";
                else ans+="0";
            }
            else if(a==3)
            {
                if(b==2) ans+="1";
                else ans+="0";
            }
            else if(a==4)
            {
                if(b==6) ans+="1";
                else ans+="0";
            }
            else if(a==6)
            {
                if(b==4) ans+="1";
                else ans+="0";
            }
            }
            else ans+="00";
        }
        else ans+="000";
    }
    else ans="0000";
    cout<<ans<<endl;
    return 0;
}