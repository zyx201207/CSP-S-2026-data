#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        printf("1");
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            printf("1");
            if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')){
                printf("1");
                if(abs(s2[2]-s4[2])==1){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                printf("00");
            }
        }
        else{
            printf("000");
        }
    }
    else{
        printf("0000");
    }
    return 0;
}
