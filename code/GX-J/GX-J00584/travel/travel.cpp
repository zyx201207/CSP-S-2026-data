#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    bool flag_1=false;
    bool flag_2=false;
    bool flag_3=false;
    bool flag_4=false;
    if(c1==c3){
        flag_1=true;
    }
    else{
        cout<<"0000";
        return 0;
    }
    string a="";
    string b="";
    char num1;
    char num2;
    for(int i=0;i<c2.size();i++){
        if(c2[i]>='0'&&c2[i]<='9'){
            a+=c2[i];
        }
        else{
            num1=c2[i];
        }
    }
    for(int i=0;i<c4.size();i++){
        if(c4[i]>='0'&&c4[i]<='9'){
            b+=c4[i];
        }
        else{
            num2=c4[i];
        }
    }
    if(a==b){
        flag_2=true;
        if(!(num1=='C'&&num2=='D')||!(num1=='D'&&num2=='C')&&(num1-num2==1||num2-num1==1)){
            flag_3=true;
        }
        else{
            flag_3=false;
            return 0;
        }
        /*else*/ if(num1-num2==1||num2-num1==1){
           // flag_3=true;
            flag_4=true;
        }
    }
    else{
        /*if((num1=='D'&&num2=='C')||(num1=='C'&&num2=='D')){
            flag_3=false;
            return 0;
        }*/
        /*else*/ if((num1!='D' && num2!='C')||(num1!='C' && num2!='D')){
                flag_3=true;
                if((num1-1==num2)||(num2-1==num1)){
                    flag_4=true;
                }
        }
        else{
            flag_3=false;
            return 0;
        }

    }
    if(flag_1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(flag_2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(flag_3){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(flag_4){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
