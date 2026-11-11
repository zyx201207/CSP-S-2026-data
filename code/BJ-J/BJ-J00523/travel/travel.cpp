#include <bits/stdc++.h>
using namespace std;
bool tc(char a,char b){
    if(a>='D' && b>='D'){
        return 1;
    }
    if(a<'D' && b<'D'){
        return 1;
    }
    return 0;
}
bool xl(char a,char b){
    if(a>='D' && b>='D'){
        return 1;
    }
    if(abs(a-b)==1 && a<'D' && b<'D'){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<'1';
            if(tc(s1[2],s2[2])){
                cout<<'1';
                if(xl(s1[2],s2[2])){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
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
