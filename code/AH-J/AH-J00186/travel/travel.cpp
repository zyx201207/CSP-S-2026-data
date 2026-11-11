#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int i,a1,a2;
char b1,b2;
bool tc(char a,char b)
{
    bool t;
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))
    {
        t=1;
    }
    else
    {
        if((a=='D'||a=='F')&&(b=='D'||b=='F'))
        {
            t=1;
        }
        else t=0;
    }
    return t;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(i=0;i<3;i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            a1*=10;
            a1+=s1[i]-'0';
        }
        else
        {
            b1=s1[i];
        }
        if(s2[i]>='0'&&s2[i]<='9')
        {
            a2*=10;
            a2+=s2[i]-'0';
        }
        else
        {
            b2=s2[i];
        }
    }
   if(c1==c2)
    {
        cout<<1;
        if(a1==a2)
        {
           cout<<1;
           if(tc(b1,b2)==1)
           {
               cout<<1;
               if((b1-b2)==1||(b2-b1)==1)
               {
                   cout<<1;
               }
               else cout<<"0";
           }
           else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
    fclose(stdout);
}
