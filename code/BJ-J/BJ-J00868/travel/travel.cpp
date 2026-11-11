#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int ans[4],a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans[0]=1;
        a+=(s1[0]-'0')*10;
        b+=(s2[0]-'0')*10;
        a+=(s1[1]-'0');
        b+=(s2[1]-'0');
        if(a==b)
        {
            ans[1]=1;
            if(s1[2]=='B')
            {
                if(s2[2]=='A'||s2[2]=='C')
                {
                    ans[2]=1;
                    ans[3]=1;
                }
            }
            else if(s1[2]=='A')
            {
                if(s2[2]=='B')
                {
                    ans[2]=1;
                    ans[3]=1;
                }
                else if(s2[2]=='C')
                {
                    ans[2]=1;
                }
            }
            else if(s1[2]=='C')
            {
                if(s2[2]=='B')
                {
                    ans[2]=1;
                    ans[3]=1;
                }
                else if(s2[2]=='A')
                {
                    ans[2]=1;
                }
            }
            else if(s1[2]=='D')
            {
                if(s2[2]=='F')
                {
                    ans[2]=1;
                    ans[3]=1;
                }
            }
            else if(s1[2]=='F')
            {
                if(s2[2]=='D')
                {
                    ans[2]=1;
                    ans[3]=1;
                }
            }
        }
    }
    for(int i=0;i<=3;i++) cout<<ans[i];
    return 0;
}