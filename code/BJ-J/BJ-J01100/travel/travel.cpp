#include<iostream>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            char ss1,ss2;
            ss1=s1[2];
            ss2=s2[2];
            if(ss1>'C'&&ss2>'C'){
                cout<<'1'<<'1';
            }else if(ss1<='C'&&ss2<='C'){
                cout<<'1';
                if(ss1+1==ss2||ss1-1==ss2){
                    cout<<'1';
                }else{
                    cout<<'0';
                }

            }else{
            cout<<'0'<<'0';
            }

        }else{
            cout<<'0'<<'0'<<'0';
        }
    }else{
        cout<<'0'<<'0'<<'0'<<'0';
    }

    return 0;
}