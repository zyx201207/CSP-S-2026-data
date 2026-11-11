#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
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
    int num1=s1[2]-'A'+1,num2=s2[2]-'A'+1;
    //cout<<endl<<s1[2]<<' '<<s2[2]<<' '<<num1<<' '<<num2<<endl;
    if(num1>=1&&num1<=3&&num2>=1&&num2<=3||num1>=4&&num1<=5&&num2>=4&&num2<=5){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(num1+1==num2||num1-1==num2){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
