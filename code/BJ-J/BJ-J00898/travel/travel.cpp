#include<iostream>
using namespace std;
string ans(string s1,string s2,string s3,string s4){
    string s;
    //是否在同一车厢
    if(s1==s3){
        s="1";
        //是否在同一排
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            s+="1";
            //是否在同一侧
            if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){
                s+="1";
                //是否相邻
                if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='B')){
                    s+="1";
                }
                else{
                    s+="0";
                }
            }
            else if((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')){
                s+="11";
            }
            else{
                s+="00";
            }
        }
        else{
            s+="000";
        }
    }
    else{
        s="0000";
    }
    return s;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    cout<<ans(s1,s2,s3,s4);
    return 0;
}
