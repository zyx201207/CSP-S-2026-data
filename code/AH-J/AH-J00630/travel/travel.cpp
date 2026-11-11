#include<bits/stdc++.h>
using naemspace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int suml,sumn;
    string suml1,sumn1;
    cin>>suml>>suml1>>sumn>>sumn1;
    if(suml==sumn) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(int(suml1)/100==int(sumn1)/100) cout<<"1"
    else{
        cout<<"000";
        return 0;
    }
    int a=suml1/10%10*10,b=suml1%10,c=sumn1/10%10*10,d=sumn1%10
    if(a+b>='A'&&a+b<='C'&&c+d>='A'&&c+d<='C'||(a+b=='D'&&c+d<='F')||(c+d=='D'&&a+b<='F')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(a+b>='A'&&a+b<='C'&&c+d>='A'&&c+d<='C'){
        if(a+b+1==c+d||a+b-1==c+d){
            cout<<"1";
            return 0;
        }
        else{
            cout<<"0";
            return 0;
        }
    }else{
        cout<<"1";
    }
    return 0;
}
