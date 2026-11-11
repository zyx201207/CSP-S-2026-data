#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            if(b[2]-'A'<=2&&d[2]-'A'<=2||d[2]=='F'&&b[2]=='D'||d[2]=='D'&&b[2]=='F'){
                if(d[2]=='F'&&b[2]=='D'||d[2]=='D'&&b[2]=='F'){
                    printf("1111");
                }else if(b[2]=='A'){
                    if(d[2]=='B'){
                        printf("1111");
                    }else{
                        printf("1110");
                    }
                }else if(b[2]=='B'){
                    if(d[2]=='C'){
                        printf("1111");
                    }else{
                        printf("1110");
                    }
                }else if(b[2]=='C'){
                    if(d[2]=='B'){
                        printf("1111");
                    }else{
                        printf("1110");
                    }
                }
            }else{
                printf("1100");
            }
        }else{
            printf("1000");
        }
    }else{
        printf("0000");
    }
    return 0;
}
