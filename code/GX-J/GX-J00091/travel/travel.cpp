#include<iostream>
#include<string>
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::string c1,s1,c2,s2;
    std::string out="0000";
    std::cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&((c1[0]=='0'&&c2[0]=='0')||(c1[0]=='1'&&c1[1]>='1'&&c1[1]<='7'&&c2[0]=='1'&&c2[1]>='1'&&c2[1]<='7'))){
        out[0]='1';
    }
    if(s1[1]==s2[1]){
        out[1]='1';
    }
    if(s1[2]<='C'&&s2[2]<='c'&&s1[2]>='A'&&s2[2]>='A'){
        out[2]='1';
    }
    else if(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D'){
        out[2]='1';
    }
    if((int)s1[2]-s2[2]<=1){
        out[3]='1';
    }
    std::cout<<out;
    return 0;
}
