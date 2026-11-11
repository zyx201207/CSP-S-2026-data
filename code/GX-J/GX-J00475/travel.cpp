#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag,flag1;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        flag1=true;
    }
    else{
        cout<<"0";
        flag1=false;
    }
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]&&flag1==true){
            flag=true;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag==true){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&flag1==true&&flag==true||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&flag1==true&&flag==true){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(char(int(s1[2])+1)==s2[2]&&flag1==true&&flag==true||char(int(s1[2])-1)==s2[2]&&flag1==true&&flag==true){
        if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
            cout<<"0";
        }
        else{
            cout<<"1";
        }
    }
    else{
        cout<<"0";
    }

    return 0;
}
