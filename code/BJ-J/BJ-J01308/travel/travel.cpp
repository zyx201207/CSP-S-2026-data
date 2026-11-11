#include<iostream>
#include<cstdio>
using namespace std;
int c1,c2,z1,z2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    z1=s1[2]-'A',z2=s2[2]-'A';
    if((z1<=2&&z2<=2)||(z1>=3&&z2>=3)){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((z1+1==z2||z2+1==z1)&&!((z1==2&&z2==3)||(z1==3&&z2==2))){
        cout<<1;
    }else{
        cout<<"0";
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
