#include <iostream>
#include <string>
using namespace std;
int main(){
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        printf("1");
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            printf("1");
            if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
                printf("1");
                if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1){
                    printf("1");
                }else{
                        printf("0");
                    }
            }else{
                if((a2[2]=='D'||a2[2]=='F')&&b2[2]=='D'||b2[2]=='F'){
                printf("11");
                }else{
                printf("00");
                }
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    return 0;
}
