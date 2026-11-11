#include <iostream>
using namespace std;
int main(){
    freopen("travel.in",r,stdin);
    frepoen("travel.out",w,stdout);
    int a,b;
    string s1,s2;
    bool a1=false,a2=false,a3=false;
    cin>>a>>s1>>b>>s2;

    if(a==b){
        cout<<1;
        a1=true;
    }else{
        cout<<0;
    }


    if(((s1[0]==s2[0])&&(s1[1]==s2[1]))&&(a1==true)){
        cout<<1;
        a2=true;
    }else{
        cout<<0;
    }

    if((a1==true)&&(a2==true)&&((a1=='D'&&a2=='F')||(a1=='F'&&a2=='D')||((s1[2]<'D')&&(s2[2]<'D')))){
        cout<<1;
        a3=true;
    }else{
        cout<<0;
    }


    if((a1==true&&a2==true&&a3==true)&&((abs(s1[2]-s2[2])==1)||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[202]=='D'))){
        cout<<1;
    }else{
        cout<<0;
    }


    return 0;
}
