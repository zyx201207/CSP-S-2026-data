#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!='E'&&s2[2]!='E')){
                printf("1");
                if(abs((int)s1[2]-s2[2])==1||(s1[2]=='F'||s2[2]=='F'&&abs((int)s1[2]-s2[2])==2))printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
