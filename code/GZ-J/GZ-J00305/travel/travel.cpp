//GZ-J00305 È½å¶Ñï Ê®¶þÖÐ 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

    std::string s,s1,a,a1;


    std::cin>>s>>s1>>a>>a1;

    if(s==a)
    {
        cout<<"1";

    if(s==a&&s1[0]==a1[0]&&s1[1]==a1[1])
    {
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(s==a&&s1[0]==a1[0]&&s1[1]==a1[1]&&s1[2]<a1[2]||a1[2]<s1[2])
    {
        if(s1[2]<='C'&&s1[2]>='A'&&a1[2]>='A'&&a1[2]<='C'||a1[2]<='C'&&a1[2]>='A'&&s1[2]>='A'&&s1[2]<='C'||s1[2]=='D'&&a1[2]=='F'||a1[2]=='D'&&s1[2]=='F')
        {
            cout<<"1";
        }
         else
         {
             cout<<"00";
             return 0;
         }
    }
    else{
            cout<<"00";
            return 0;
    }

        if(s1[2]=='A'&&a1[2]=='B'||s1[2]=='B'&&a1[2]=='A'||s1[2]=='B'&&a1[2]=='C'||s1[2]=='C'&&a1[2]=='B'||s1[2]=='D'&&a1[2]=='F'||s1[2]=='F'&&a1[2]=='D'){
               cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    if(s!=a){
        cout<<"0000";
        return 0;
    }

    return 0;
}
