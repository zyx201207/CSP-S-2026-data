#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)printf("%d",1);
    else {printf("0000");return 0;}
    string num1=s1.substr(0,2),num2=s2.substr(0,2);
    if(num1==num2)printf("%d",1);
    else {printf("000");return 0;}
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
        {
            printf("%d",1);
            if(s1[2]==s2[2]+1||s1[2]+1==s2[2])printf("%d",1);
            else printf("%d",0);
        }
        else printf("00");
    }
    else if(s1[2]=='D'||s1[2]=='F')
    {
        if(s2[2]=='D'||s2[2]=='F')
        {
            printf("%d",11);
        }
        else printf("00");
    }
    return 0;
}
