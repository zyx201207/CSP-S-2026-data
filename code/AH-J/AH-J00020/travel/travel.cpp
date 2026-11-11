#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
bool f(char x1,char x2){
    if(x1=='A'&&x2=='B'||x1=='A'&&x2=='C'||x1=='B'&&x2=='C'){
        return true;
    }
    if(x1=='D'&&x2=='F'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(f(s1[2],s2[2])||f(s2[2],s1[2])){
                cout<<"1";
                if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
