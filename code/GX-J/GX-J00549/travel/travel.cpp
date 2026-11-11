#include <iostream>
using namespace std;
string s,s1,s2,s3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>s2>>s3;
    if(s==s2){
        cout <<"1";
        if(s1[0]==s3[0] && s1[1]==s3[1]){
            cout <<"1";
            if(s1[2]=='A'){
                if(s3[2]=='B' || s3[2]=='C'){
                    cout <<"1";
                    if(s3[2]=='B'){
                        cout <<"1";
                    }
                    else{
                        cout <<"0";
                    }
                }
                else{
                    cout <<"0";
                }
            }
            if(s1[2]=='B'){
                if(s3[2]=='A' || s3[2]=='C'){
                    cout <<"1";
                    if(s3[2]=='A'||s3[2]=='B'){
                        cout <<"1";
                    }
                    else{
                        cout <<"0";
                    }
                }
                else{
                    cout <<"0";
                }
            }
            if(s1[2]=='C'){
                if(s3[2]=='A'||s3[2]=='B'){
                    cout <<"1";
                    if(s3[2]=='B'){
                        cout <<"1";
                    }
                    else{
                        cout <<"0";
                    }
                }
                else{
                    cout <<"0";
                }
            }
            if(s1[2]=='D'){
                if(s3[2]=='F'){
                    cout <<"1";
                    if(s3[2]=='F'){
                        cout <<"1";
                    }
                    else{
                        cout <<"0";
                    }
                }
                else{
                    cout <<"0";
                }
            }
            if(s1[2]=='F'){
                if(s3[2]=='D'){
                    cout <<"1";
                }

    else{
        cout <<"0";
    }
         if(s3[2]=='D'){
                        cout <<"1";
                    }
                    else{
                        cout <<"0";
                    }
                }
        }

    }
}

