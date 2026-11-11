#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string att,btt;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>att>>b1>>btt;
    if(a1==b1){
        cout<<1;
        if(att[0]==btt[0] && att[1]==btt[1]){
            cout<<1;
            if(att[2]=='A'&&btt[2]=='B'){
                cout<<"11";
                return 0;
            }
            if(att[2]=='A'&&btt[2]=='C'){
                cout<<"10";
                return 0;
            }
            if(att[2]=='A'&&btt[2]=='D'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='A'&&btt[2]=='F'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='B'&&btt[2]=='A'){
                cout<<"11";
                return 0;
            }
            if(att[2]=='B'&&btt[2]=='C'){
                cout<<"11";
                return 0;
            }
            if(att[2]=='B'&&btt[2]=='D'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='B'&&btt[2]=='F'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='C'&&btt[2]=='A'){
                cout<<"10";
                return 0;
            }
            if(att[2]=='C'&&btt[2]=='B'){
                cout<<"11";
                return 0;
            }
            if(att[2]=='C'&&btt[2]=='D'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='C'&&btt[2]=='F'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='D'&&btt[2]=='A'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='D'&&btt[2]=='B'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='D'&&btt[2]=='C'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='D'&&btt[2]=='F'){
                cout<<"11";
                return 0;
            }
            if(att[2]=='F'&&btt[2]=='A'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='F'&&btt[2]=='B'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='F'&&btt[2]=='C'){
                cout<<"00";
                return 0;
            }
            if(att[2]=='F'&&btt[2]=='D'){
                cout<<"11";
                return 0;
            }
            cout<<"00";
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
}
