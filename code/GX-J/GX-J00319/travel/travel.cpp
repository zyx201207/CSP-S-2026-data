#include<bits/stdc++.h>
using namespace std;
int main(){
    string C1,S1,C2,S2;
    char a1='0',a2='0',a3='0',a4='0';
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>C1>>S1>>C2>>S2;
    if(C1==C2)a1='1';
    if(a1=='1'){
        if(S1[0]==S2[0] && S1[1]==S2[1]) a2='1';
    }
    if(a2=='1'){
        if(S1[2]=='C'||S1[2]=='B'||S1[2]=='A'){
            if(S2[2]=='C'||S2[2]=='B'||S2[2]=='A') a3='1';
            }

        if(S1[2]=='F'||S1[2]=='D'){
            if(S2[2]=='F'||S2[2]=='D') a3='1';
        }
    }
    if(a3=='1'){
        if((S1[2]=='B'&& S2[2]=='A')||(S1[2]=='A'&& S2[2]=='B')||(S1[2]=='C'&& S2[2]=='B')||(S1[2]=='B'&& S2[2]=='C')||(S1[2]=='F'&& S2[2]=='D')||(S1[2]=='D'&& S2[2]=='F'))a4='1';
    }
    cout<<a1<<a2<<a3<<a4;
 //   fclose(stdout);
    return 0;
}
