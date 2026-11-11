#include<iostream>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1[1]!=s3[1]||s1[0]!=s3[0]){
        cout<<"0000";
    }else{
        cout<<"1";
        if(s2[0]!=s4[0]||s2[1]!=s2[1]){
            cout<<"000";
        }else if(s2[0]==s4[0]&&s2[1]==s4[1]){
            cout<<"1";
            if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){
                cout<<"1";
                if(((s2[2]=='A'||s2[2]=='C')&&s4[2]=='B')||(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'))){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else if((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')){
                cout<<"11";
            }else cout<<"00";
        }else{
            cout<<"000";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
