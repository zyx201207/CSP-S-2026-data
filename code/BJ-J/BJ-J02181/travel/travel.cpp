#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(s1[1]!=s1[2]||s1[2]!=s2[2]){
            cout<<"000";
        }
        else{
            cout<<"1";
            int a,b;
            if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
                a=1;
            }
            else{
                a=0;
            }
            if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
                b=1;
            }
            else{
                b=0;
            }
            if(a==b){
                cout<<"1";
                if(a==0){
                    cout<<"1";
                }
                else if(s1[3]=='B'||s2[3]=='B'){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}