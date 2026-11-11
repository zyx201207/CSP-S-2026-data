#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool op=1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    s1=" "+s1;
    s2= " "+s2;
    s3=" "+s3;
    s4=" "+s4;
    if(s1==s3)
    {
       printf("1");
    }else op=0,printf("0000");
    if(op==1){
            bool op1=1;
        if(s2[1]==s4[1]&&s2[2]==s4[2]){
            printf("1");
            if(((s2[3]>='A'&&s2[3]<='C')&&(s4[3]>='A'&&s4[3]<='C'))||((s2[3]=='D'&&s4[3]=='F')||(s2[3]=='F'&&s4[3]=='D'))){
                printf("1");
                if((char(s2[3]+1)==s4[3]||char(s2[3]-1)==s4[3])||((s2[3]=='D'&&s4[3]=='F')||(s2[3]=='F'&&s4[3]=='D'))){
                    printf("1");
                }else printf("0");
            }else printf("00");

        }else printf("000");
    }
    return 0;
}
