#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string c1,c2,s1,s2;
int p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) cout<<"1";
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    char w1=s1[2],w2=s2[2];
    if(char(w1-1)==w2||char(w2-1)==w1){
        if(w1=='C'&&w2=='D'){
            cout<<"0";
            return 0;
        }else{
            cout<<"1";
        }
    }else{
        cout<<"0";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
