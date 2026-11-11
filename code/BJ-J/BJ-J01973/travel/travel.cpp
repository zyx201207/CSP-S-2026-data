#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b12,b22;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    b1=false;
    b2=false;
    b12=false;
    b22=false;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<"1";
            for(char i='A';i<='C';i++){
                if(s1[2]==i) b1=true;
                if(s2[2]==i) b2=true;
            }
            for(char i='D';i<='F';i++){
                if(s1[2]==i) b12=true;
                if(s2[2]==i) b22=true;
            }
            if(b1 && b2 || b12 && b22){
                cout<<"1";
                b1=false;
                if(s1[2]=='A' && s2[2]=='B') b1=true;
                if(s2[2]=='A' && s1[2]=='B') b1=true;
                if(s1[2]=='B' && s2[2]=='C') b1=true;
                if(s2[2]=='B' && s1[2]=='C') b1=true;
                if(s1[2]=='D' && s2[2]=='F') b1=true;
                if(s2[2]=='D' && s1[2]=='F') b1=true;
                if(b1) cout<<"1";
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}