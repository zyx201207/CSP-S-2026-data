#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        bool flag=1;
        for(int i=0;i<2;i++)
        {
            if(s1[i]!=s2[i])
            {
                cout<<"1000";
                flag=0;
                break;
            }
        }
        if(flag)
        {

            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
            {
                if(abs(s1[2]-s2[2])<=1&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C'))
                {
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
            {
                if(abs(s1[2]-s2[2])<=1&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C'))
                {
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}