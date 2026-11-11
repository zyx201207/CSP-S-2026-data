#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
int pd1=0,pd2=0,pd3=0,pd4=0;
cin>>c1>>s1>>c2>>s2;
if(c1[0]==c2[0]&&c1[1]==c2[1])
{
    pd1=1;//same car
    if(s1[0]==s2[0]&&s1[1]==s2[1]) {
        pd2=1;//same row
        if(int(s1[2])>=int('D')&&int(s2[2])>=int('D')||int(s1[2])<=int('C')&&int(s2[2])<=int('C')){
            pd3=1;//same side
            if(int(s1[2])>=int('D')&&int(s2[2])>=int('D'))
                pd4=1;//in DFside
            else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
                pd4=0;//in ABCside & !=A&C
            else
                pd4=1;//ok
        }

}
}
cout<<pd1<<pd2<<pd3<<pd4;
return 0;

}
