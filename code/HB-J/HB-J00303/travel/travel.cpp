#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c[2];
    string s[2];
    for(int i=0;i<2;i++){
        cin>>c[i]>>s[i];
    }
    if(c[0]==c[1]){
        cout<<"1";
        if(s[0][0]==s[1][0]&&s[1][1]==s[0][1]){
            cout<<"1";
            if(s[0][2]==s[1][2]-1&&s[0][2]-'A'!=2||s[0][2]==s[1][2]+1&&s[0][2]-'A'!=3){
                cout<<"11";
            }
            else{
                if(s[0][2]==s[1][2]-2||s[0][2]==s[1][2]+2){
                    cout<<"10";
                }
                else{
                    cout<<"00";
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}