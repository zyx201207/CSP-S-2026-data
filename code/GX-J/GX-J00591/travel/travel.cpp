#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int i,n,p=0;
    char s1[30],s2[30],c1[30],c2[30],sum[20],l1[20],l2[20];
    cin>>s1>>s2>>c1>>c2;
    for(i=0;i<20;++i)
    {
        l1[i]='\0';
        l2[i]='\0';
    }
    n=strlen(c2);
    l1[0]=s2[2];
    l2[0]=c2[2];
    if(strcmp(s1,c1)==0)
    {
        cout<<"1";
        s2[2]='\0';
        c2[2]='\0';
        if(strcmp(s2,c2)==0)
        {
            cout<<"1";
            if(l1[0]=='D' && l2[0]=='F')
            {
                cout<<"11";
                return 0;
            }
            else if((l1[0]=='B'||l1[0]=='A'||l1[0]=='C')&&(l2[0]=='B'||l2[0]=='A'||l2[0]=='C')&&l1[0]!=l2[0])
            {
                cout<<"1";
                if((l1[0]+2==l2[0])||(l2[0]+2==l1[0]))
                {
                    cout<<"0";
                    return 0;
                }
                else
                {
                    cout<<"1";
                    return 0;
                }
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }

    }
    cout<<"0000";
    return 0;
}
