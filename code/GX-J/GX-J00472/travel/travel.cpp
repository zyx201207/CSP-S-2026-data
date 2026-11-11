#include<bits/stdc++.h>
using namespace std;

string a,a1,b,b1;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b){
        printf("%s","1");
        string xa,xb;
        char xa1,xb1;
        for(int i=0;i<=a.size();i++){
            if(i!=a.size()){
                xa+=a1[i];
                xb+=b1[i];
            }
            else{

                xa1=char(a1[i]);
                xb1=char(b1[i]);
            }
        }
        if(xa==xb){
            printf("%s","1");
            if((xa1>='A'&&xa1<='C'&&xb1>='A'&&xb1<='C')||(xa1>='D'&&xa1<='F'&&xb1>='D'&&xb1<='F')){
                printf("%s","1");
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s","0");
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
            else{//3
                printf("%s%s","0","0");
                return 0;
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s","0");
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
        }
        else{//2
            printf("%s%s%s","0","0","0");
            return 0;
            if((xa1>='A'&&xa1<='C'&&xb1>='A'&&xb1<='C')||(xa1>='D'&&xa1<='F'&&xb1>='D'&&xb1<='F')){
                printf("%s","1");
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s%s","0","0");
                    return 0;
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
            else{//3
                printf("%s%s","0","0");
                return 0;
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s","0");
                    return 0;
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
        }
    }
    else{//1
        printf("%s%s%s%s","0","0","0","0");
        return 0;
        string xa,xb;
        char xa1,xb1;
        for(int i=0;i<=a.size();i++){
            if(i!=a.size()){
                xa+=a1[i];
                xb+=b1[i];
            }
            else{
                xa1=char(a1[i]);
                xb1=char(b1[i]);
            }
        }
        if(xa==xb){
            printf("%s","1");
            if((xa1>='A'&&xa1<='C'&&xb1>='A'&&xb1<='C')||(xa1>='D'&&xa1<='F'&&xb1>='D'&&xb1<='F')){
                printf("%s","1");
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s","0");
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
            else{//3
                printf("%s%s","0","0");
                return 0;
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s","0");
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
        }
        else{//2
            printf("%s%s%s","0","0","0");
            return 0;
            if((xa1>='A'&&xa1<='C'&&xb1>='A'&&xb1<='C')||(xa1>='D'&&xa1<='F'&&xb1>='D'&&xb1<='F')){
                printf("%s","1");
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s%s","0","0");
                    return 0;
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
            else{//3
                printf("%s%s","0","0");
                return 0;
                if((xa1=='C'&&xb1=='D')||(xa1=='D'&&xb1=='C')){
                    printf("%s%s","0","0");
                    return 0;
                }
                else{//4 t
                    if((xa1-1==xb1)||(xa1+1==xb1)) printf("%s","1");
                    else printf("%s","0");
                }
            }
        }
    }
    return 0;
}
