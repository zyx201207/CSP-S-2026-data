#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(a==b){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')||(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]))){
       cout<<1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
