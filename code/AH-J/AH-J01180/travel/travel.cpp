#include<vector>
#include<iostream>
std::string c1,s1,c2,s2,ans="";
bool sameline(){
    return s1[0]==s2[0] && s1[1]==s2[1];
}
bool  side(char a){
    return 'A'<=a && a<='C';
}
bool sameside(){
    return side(s1[2])==side(s2[2]);
}
bool near(){
    if(s1[2]=='D') return s2[2]=='F';
    if(s1[2]=='D') return s2[2]=='D';
    return s1[2]+1==s2[2] || s1[2]-1==s2[2];
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+='1';
        if(sameline()){
            ans+='1';
            if(sameside()){
                ans+='1';
                // if(near()){
                //     ans+='1';
                // }
                // else{
                //     ans+='0';
                // }
                ans+=near()+'0';
            }
            else{
                ans+="00";
            }
        }
        else{
            ans+="000";
        }
    }
    else{
        ans+="0000";
    }
    
    std::cout<<ans<<"\n";
    return 0;

}