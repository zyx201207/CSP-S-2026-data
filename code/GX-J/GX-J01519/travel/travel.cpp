#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

string c1,s1,c2,s2,ans;
char s_[7]={'A','B','C','X','D','F'};
int pos1,pos2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<6;i++)
    {
        if(s_[i]==s1[2])
        {
            pos1=i;
            break;
        }
    }
    for(int i=0;i<6;i++)
    {
        if(s_[i]==s2[2])
        {
            pos2=i;
            break;
        }
    }
    if(c1==c2)
    {
        ans+='1';
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            ans+='1';
            if(pos1+pos2<=3 || pos1+pos2==9)
            {
                ans+='1';
                if(abs(pos1-pos2)==1)
                {
                    ans+='1';
                }
                else ans="1110";
            }
            else ans="1100";
        }
        else ans="1000";
    }
    else ans="0000";

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
